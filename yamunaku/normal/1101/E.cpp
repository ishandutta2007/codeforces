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
  cin.tie(0);ios::sync_with_stdio(false);
  int n;
  cin >> n;
  char c;
  int x,y;
  int ma=0,mi=0,mma,mmi;
  for(int i=0;i<n;i++){
    cin >> c >> x >> y;
    if(c=='+'){
      ma=max(ma,max(x,y));
      mi=max(mi,min(x,y));
    }else{
      mma=max(x,y);
      mmi=min(x,y);
      if(mma>=ma&&mmi>=mi){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}