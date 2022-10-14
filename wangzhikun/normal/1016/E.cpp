#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double eps=1e-9;
bool equal(double x, double y){
  return x>y-eps and x<y+eps;
}
const int N=202020;
LL sy, a, b;
LL n, l[N], r[N], q, x[N], y[N];
vector<double> cand;
double jiou(double x1, double y1,
            double x2, double y2){
  return x1+(x2-x1)*(0-y1)/(y2-y1);
}
int id(double vv){
  int bl=0, br=cand.size()-1;
  while(bl <= br){
    int mid=(bl+br)>>1;
    if(equal(cand[mid], vv)) return mid+1;
    if(cand[mid] < vv) bl=mid+1;
    else br=mid-1;
  }
  assert(false);
  return -1;
}

int ps[N<<2], sz;
double vps[N<<2], ja[N], jb[N];
void go(){
  for(int i=0; i<n; i++){
    ps[id(l[i])]++;
    ps[id(r[i])]--;
  }
  for(int i=1; i<=sz; i++) ps[i]+=ps[i-1];
  for(int i=2; i<=sz; i++){
    if(ps[i-1]) vps[i]=cand[i-1]-cand[i-2];
    vps[i]+=vps[i-1];
  }
  for(int i=0; i<q; i++){
    int i1=id(ja[i]);
    int i2=id(jb[i]);
    if(i1 > i2) swap(i1, i2);
    if(i1 == i2){
      puts("0");
      continue;
    }
    double tot=cand[i2-1]-cand[i1-1];
    double has=vps[i2]-vps[i1];
    printf("%.12f\n", has*(b-a)/tot);
  }
}

int main(){
  scanf("%lld%lld%lld", &sy, &a, &b);
  scanf("%lld", &n);
  for(int i=0; i<n; i++) scanf("%lld%lld", &l[i], &r[i]);
  scanf("%lld", &q);
  for(int i=0; i<q; i++) scanf("%lld%lld", &x[i], &y[i]);

  for(int i=0; i<n; i++){
    cand.push_back(l[i]);
    cand.push_back(r[i]);
  }
  for(int i=0; i<q; i++){
    cand.push_back(ja[i]=jiou(x[i], y[i], a, sy));
    cand.push_back(jb[i]=jiou(x[i], y[i], b, sy));
  }
  
  {
    sort(cand.begin(), cand.end());
    sz=1;
    for(size_t i=1; i<cand.size(); i++){
      if(equal(cand[i], cand[sz-1])) continue;
      cand[sz++]=cand[i];
    }
    cand.resize(sz);
  }
  go();
}