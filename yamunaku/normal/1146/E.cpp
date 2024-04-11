#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

struct SegmentTree {
private:
  int n;
  vector<pair<int,int>> node;

  void merge(pair<int,int> &l,pair<int,int> &r){
    if(r.first){
      l.first=1;
      l.second=r.second;
    }else{
      l.second*=r.second;
    }
  }

public:

  SegmentTree(vector<int> v) {
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1);
    for(int i=0; i<sz; i++) node[i+n-1] = {1,v[i]};
    for(int i=n-2; i>=0; i--) node[i] = {0,1};
  }

  int getval(int x) {
    return node[x+n-1].second;
  }

  void set(){
    for(int i=0; i<=n-2; i++){
      merge(node[2*i+1],node[i]);
      merge(node[2*i+2],node[i]);
      node[i]={0,1};
    }
  }

  void update(int a, int b, pair<int,int> &q, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    if(r <= a || b <= l) return;
    if(a <= l && r <= b){
      merge(node[k],q);
      return;
    }
    merge(node[2*k+1],node[k]);
    merge(node[2*k+2],node[k]);
    node[k]={0,1};
    update(a, b, q, 2*k+1, l, (l+r)/2);
    update(a, b, q, 2*k+2, (l+r)/2, r);
  }

  void vis(){
    int j=0;
    for(int i=0;i<2*n-1;i++){
      if(i+1==(1<<j)) cout << endl,j++;
      cout <<  "{" <<node[i].first  <<"," << node[i].second << "}" << " ";
      
    }
    cout << endl;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  vector<pair<int,int>> ab(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    ab[i]={abs(a[i]),i};
  }

  sort(all(ab));
  vector<int> v(n);
  for(int i=0;i<n;i++){
    if(a[ab[i].second]>=0) v[i]=1;
    else v[i]=-1;
  }
  SegmentTree seg(v);

  char c;
  int x;
  pair<int,int> p={0,IINF};
  pair<int,int> g={0,-1},ps={1,1},ng={1,-1};
  // for(int i=0;i<n;i++){
  //   cout << ab[i].first << " ";
  // }
  // cout << endl;
  // for(int i=0;i<n;i++){
  //   cout << ab[i].second << " ";
  // }
  // cout << endl;
  for(int i=0;i<q;i++){
    cin >> c >> x;
    p.first=abs(x);
    if(x>=0){
      if(c=='>'){
        p.second=IINF;
        int idx=lower_bound(all(ab),p)-ab.begin();
        seg.update(idx,n,ng);
      }else{
        p.second=-1;
        int idx=lower_bound(all(ab),p)-ab.begin();
        if(idx>0) seg.update(0,idx,g);
        seg.update(idx,n,ps);
      }
    }else{
      if(c=='>'){
        p.second=-1;
        int idx=lower_bound(all(ab),p)-ab.begin();
        if(idx>0) seg.update(0,idx,g);
        seg.update(idx,n,ng);
      }else{
        p.second=IINF;
        int idx=lower_bound(all(ab),p)-ab.begin();
        seg.update(idx,n,ps);
      }
    }

    // seg.set();
    // vector<int> tmp=a;
    // for(int i=0;i<n;i++){
    //   tmp[ab[i].second]*=seg.getval(i);
    // }
    // for(int i=0;i<n;i++){
    //   cout << tmp[i] << " ";
    // }
    // cout << endl;
  }

  seg.set();
  for(int i=0;i<n;i++){
    a[ab[i].second]=abs(a[ab[i].second])*seg.getval(i);
  }
  for(int i=0;i<n;i++){
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}