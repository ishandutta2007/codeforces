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
  LD d;
  cout << fixed << setprecision(9);
  for(int q=0;q<t;q++){
    cin >> d;
    if(d*d-4*d>=0){
      cout << "Y" SP (d+sqrt(d*d-4*d))/2 SP (d-sqrt(d*d-4*d))/2 << endl;
    }else{
      cout << "N" << endl;
    }
  }
  return 0;
}