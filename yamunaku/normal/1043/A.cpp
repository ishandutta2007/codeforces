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
  int n;
  cin >> n;
  vector<int> a(n);
  int ma=1;
  for(int i=0;i<n;i++){
    cin >> a[i];
    ma=max(ma,a[i]);
  }
  int total=0;
  for(int i=ma;i<=500;i++){
    total=0;
    for(int j=0;j<n;j++){
      total+=i-a[j];
    }
    if(2*total>i*n){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}