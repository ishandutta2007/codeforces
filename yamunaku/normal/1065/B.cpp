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
  if(m==0){
    cout << n SP n << endl;
    return 0;
  }
  cout << max(n-2*m,0) << " ";
  for(LL i=2;i<=n;i++){
    if(i*(i-1)/2>=m){
      cout << n-i << endl;
      return 0;
    }
  }
  return 0;
}