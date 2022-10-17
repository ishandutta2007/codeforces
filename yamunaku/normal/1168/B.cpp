#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(LL i = 0; i < (n); i++)
#define repp(i, l, r) for(LL i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  CFS;
  string s;
  cin >> s;
  LL n = s.length();
  LL l=-1;
  LL ans=0;
  rep(i,n){
    repp(j,1,31){
      if(0<=i-2*j){
        if(s[i-2*j]==s[i]&&s[i-j]==s[i]){
          ans+=max(0LL,i-2*j-l)*(n-i);
          l=max(l,i-2*j);
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}