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
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<int> zen(1<<((n+1)/2),0),kou(1<<(n/2),0);
  int v=zen.size(),w=kou.size();
  for(int i=0;i<v;i++){
    for(int j=0;j<(n+1)/2;j++){
      if(i&(1<<j)) zen[i]=(zen[i]+a[j])%m;
    }
  }
  for(int i=0;i<w;i++){
    for(int j=(n+1)/2;j<n;j++){
      if(i&(1<<(j-(n+1)/2))) kou[i]=(kou[i]+a[j])%m;
    }
  }
  sort(all(zen));
  sort(all(kou));
  int ans=0;
  int x,y;
  for(int i=0;i<w;i++){
    x=distance(zen.begin(),lower_bound(all(zen),m-kou[i]))-1;
    y=distance(zen.begin(),lower_bound(all(zen),2*m-kou[i]))-1;
    ans=max(ans,kou[i]+zen[x]);
    ans=max(ans,(kou[i]+zen[y])%m);
  }
  cout << ans << endl;
  return 0;
}