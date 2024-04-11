#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  LL n,m;
  cin >> n >> m;
  vector<LL> c(m,n/m),cc(m,0);
  for(int i=1;i<=n%m;i++){
    c[i]++;
  }
  for(int i=0;i<m;i++){
    cc[i*i%m]+=c[i];
  }
  // for(int i=0;i<m;i++) cout << cc[i] << " ";
  // cout << endl;
  LL ans=cc[0]*cc[0];
  for(int i=1;i<m;i++){
    ans+=cc[i]*cc[m-i];
  }
  cout << ans << endl;
  return 0;
}