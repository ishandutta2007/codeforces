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
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  b[0]=a[0];
  for(int i=1;i<n;i++){
    b[i]=a[i]-a[i-1];
  }
  list<int> ans;
  bool okflag;
  for(int i=1;i<=n;i++){
    okflag=true;
    for(int j=0;j<i;j++){
      for(int k=1;j+k*i<n;k++){
        if(b[j]!=b[j+k*i]){
          okflag=false;
          break;
        }
      }
      if(!okflag) break;
    }
    if(okflag) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for(auto i:ans){
    cout << i << " ";
  }
  cout << endl;
  return 0;
}