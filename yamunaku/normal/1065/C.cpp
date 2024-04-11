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
  vector<LL> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  sort(h.begin(),h.end(),greater<LL>());
  if(h[0]==h[n-1]){
    cout << 0 << endl;
    return 0;
  }
  LL total=0,pre=0;
  int count=0;
  for(int i=0;i<n-1;i++){
    for(int j=h[i]-1;j>=h[i+1];j--){
      total+=i+1;
      if(total>k){
        total-=pre;
        count++;
      }
      pre=total;
    }
  }
  if(total>0) count++;
  cout << count << endl;
  return 0;
}