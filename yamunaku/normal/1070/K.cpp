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
  vector<LL> a(n);
  LL total=0;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    total+=a[i];
  }
  if(total%k){
    cout << "No" << endl;
    return 0;
  }
  LL m=total/k;
  LL t;
  vector<int> ans(k);
  int now=0;
  for(int i=0;i<n;){
    t=0;
    for(int j=i;j<n;j++){
      t+=a[j];
      if(t>m){
        cout << "No" << endl;
        return 0;
      }else if(t==m){
        ans[now]=j-i+1;
        now++;
        i=j+1;
        break;
      }
    }
  }
  cout << "Yes" << endl;
  for(int i=0;i<k-1;i++){
    cout << ans[i] << " ";
  }
  cout << ans[k-1] << endl;
  return 0;
}