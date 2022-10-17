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
  int t;
  cin >> t;
  LL a,b;
  bool okflag;
  for(int i=0;i<t;i++){
    cin >> a >> b;
    if(a-b!=1){
      cout << "NO" << endl;
      continue;
    }
    okflag=false;
    for(int j=2;j<=sqrt(a+b)+1;j++){
      if((a+b)%j==0){
        cout << "NO" << endl;
        okflag=true;
        break;
      }
    }
    if(!okflag) cout << "YES" << endl;
  }
  return 0;
}