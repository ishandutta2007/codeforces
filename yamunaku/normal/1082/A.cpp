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
  for(int q=0;q<t;q++){
    int n,x,y,d;
    cin >> n>>x>>y>>d;
    if(x%d==y%d){
      cout << abs(x-y)/d << endl;
    }else if(y%d==1){
      if(y%d==n%d){
        cout << min((x-1+d-1)/d+(y-1)/d,(n-x+d-1)/d+(n-y)/d) << endl;
      }else{
        cout << (x-1+d-1)/d+(y-1)/d << endl;
      }
    }else if(y%d==n%d){
      cout << (n-x+d-1)/d+(n-y)/d << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}