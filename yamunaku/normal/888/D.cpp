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
  LL n,k;
  cin >> n >> k;
  if(k==1){
    cout << 1 << endl;
    return 0;
  }
  if(k==2){
    cout << n*(n-1)/2+1 << endl;
    return 0;
  }
  if(k==3){
    cout << 2*n*(n-1)*(n-2)/6+n*(n-1)/2+1 << endl;
    return 0;
  }
  cout << n*(n-1)*(n-2)*(n-3)/8+n*(n-1)*(n-2)*(n-3)/4+2*n*(n-1)*(n-2)/6+n*(n-1)/2+1 << endl;
  return 0;
}