#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> p(n);
  int a,b;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    a--,b--;
    p[a].push_back((n+b-a)%n);
  }
  LL ms=0;
  for(int i=0;i<n;i++){
    sort(all(p[i]));
    ms=max(ms,(LL)p[i].size());
  }
  if(ms==1){
    for(int i=0;i<n;i++){
      LL ans=0;
      for(LL j=0;j<n;j++){
        if(p[(i+j)%n].size()==ms){
          ans=max(ans,j+p[(i+j)%n][0]);
        }
      }
      cout << n*(ms-1)+ans << " ";
    }
    return 0;
  }
  for(int i=0;i<n;i++){
    LL ans=0;
    for(LL j=0;j<n;j++){
      if(p[(i+j)%n].size()>=ms-1){
        ans=max(ans,j+p[(i+j)%n][p[(i+j)%n].size()==ms?1:0]);
      }
    }
    for(LL j=0;j<n;j++){
      if(p[(i+j)%n].size()==ms){
        ans=max(ans,n+j+p[(i+j)%n][0]);
      }
    }
    cout << n*(ms-2)+ans << " ";
  }
  cout << endl;
  return 0;
}