#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

vector<pair<int,int>> uf;

int root(int x){
  if(x==uf[x].first) return x;
  return uf[x].first=root(uf[x].first);
}

void uni(int x,int y){
  x=root(x);
  y=root(y);
  if(uf[x].second<uf[y].second) swap(x,y);
  uf[y].first=x;
  uf[x].second+=uf[y].second;
}

int main(){
  LL n,k;
  cin >> n >> k;
  uf=vector<pair<int,int>>(n);
  for(int i=0;i<n;i++){
    uf[i]={i,1};
  }
  int u,v,c;
  for(int i=0;i<n-1;i++){
    cin >> u >> v >> c;
    u--,v--;
    if(c==0) uni(u,v);
  }
  vector<LL> a(n,0);
  for(int i=0;i<n;i++){
    a[root(i)]++;
  }
  LL ans=1;
  for(int i=0;i<k;i++){
    ans=ans*n%MOD;
  }
  LL tmp;
  for(int i=0;i<n;i++){
    if(a[i]>0){
      tmp=1;
      for(int j=0;j<k;j++){
        tmp=tmp*a[i]%MOD;
      }
      ans=((ans-tmp)%MOD+MOD)%MOD;
    }
  }
  cout << ans << endl;
  return 0;
}