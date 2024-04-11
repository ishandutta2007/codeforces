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
#define CYES cout<<"YES"<<endl;
#define CNO cout<<"NO"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  int t;
  cin >> t;
  rep(q,t){
    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,n-10){
      if(s[i]=='8'){
        CYES;
         goto next;
      }
    }
    CNO;
    next:;
  }
  return 0;
}