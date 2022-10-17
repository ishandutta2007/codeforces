#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"YES"<<endl
#define CNO cout<<"NO"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> a(n,0);
  int u,v;
  rep(i,n-1){
    cin >> u >> v;
    a[u-1]++;
    a[v-1]++;
  }
  rep(i,n){
    if(a[i]==2){
      CNO;
      return 0;
    }
  }
  CYES;
  return 0;
}