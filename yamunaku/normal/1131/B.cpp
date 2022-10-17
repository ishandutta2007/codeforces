#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  int a,b,na=0,nb=0;
  int ans=1;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    if(a==na&&b==nb) continue;
    ans+=max(min(a,b)-max(na,nb)+1,0);
    if(na==nb) ans--;
    na=a,nb=b;
  }
  cout << ans << endl;
  return 0;
}