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
  vector<int> c(101,0);
  int r,m;
  for(int i=0;i<n;i++){
    cin >> r;
    for(int j=0;j<r;j++){
      cin >> m;
      c[m]++;
    }
  }
  for(int i=1;i<=100;i++){
    if(c[i]==n) cout << i << " ";
  }
  cout << endl;
  return 0;
}