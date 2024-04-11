#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> b(n);
  for(int i=0;i<n;i++){
    cin >> b[i];
  }
  int ans=k;
  vector<int> a(n-1);
  for(int i=0;i<n-1;i++){
    a[i]=b[i+1]-b[i];
  }
  sort(all(a));
  for(int i=0;i<n-k;i++){
    ans+=a[i];
  }
  cout << ans << endl;
  return 0;
}