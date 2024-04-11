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
  LL n,m;
  cin >> n >> m;
  if(n<m){
    cout << 1 << endl;
    return 0;
  }
  vector<vector<LL>> r(m,vector<LL>(m,0)),nr(m,vector<LL>(m,0));
  r[0][0]=r[0][m-1]=1;
  for(int i=1;i<m;i++){
    r[i][i-1]=1;
  }
  vector<LL> v(m,1),w(m);
  n-=m-1;
  while(n){
    if(n&1){
      for(int i=0;i<m;i++){
        w[i]=0;
        for(int j=0;j<m;j++){
          w[i]=(w[i]+r[i][j]*v[j]%MOD)%MOD;
        }
      }
      for(int i=0;i<m;i++){
        v[i]=w[i];
      }
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        nr[i][j]=0;
        for(int k=0;k<m;k++){
          nr[i][j]=(nr[i][j]+r[i][k]*r[k][j]%MOD)%MOD;
        }
      }
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        r[i][j]=nr[i][j];
      }
    }
    n/=2;
  }
  cout << v[0] << endl;
  return 0;
}