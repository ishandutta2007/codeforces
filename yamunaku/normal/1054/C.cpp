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
  vector<int> l(n),r(n);
  for(int i=0;i<n;i++) cin >> l[i];
  for(int i=0;i<n;i++) cin >> r[i];
  vector<int> ans(n,-1);
  queue<int> idx;
  int now;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(l[j]==0&&r[j]==0&&ans[j]==-1){
        ans[j]=n-i;
        idx.push(j);
      }
    }
    while(!idx.empty()){
      now=idx.front();
      idx.pop();
      for(int j=0;j<now;j++) if(ans[j]==-1) r[j]--;
      for(int j=now+1;j<n;j++) if(ans[j]==-1) l[j]--;
    }
  }
  for(int i=0;i<n;i++){
    if(l[i]!=0||r[i]!=0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for(int i=0;i<n-1;i++){
    cout << ans[i] << " ";
  }
  cout << ans[n-1] << endl;
  return 0;
}