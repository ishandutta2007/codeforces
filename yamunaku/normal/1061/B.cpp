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
  LL n,m;
  cin >> n >> m;
  vector<LL> a(n);
  LL maxa=0;
  LL ans=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    maxa=max(maxa,a[i]);
    ans+=a[i];
  }
  sort(a.begin(),a.end());
  LL x=0;
  for(int i=0;i<n;i++){
    if(x<a[i]) x++;
  }
  cout << ans-(n+(maxa-x)) << endl;
  return 0;
}