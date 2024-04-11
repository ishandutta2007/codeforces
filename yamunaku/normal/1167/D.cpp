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
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  string s;
  cin >> n >> s;
  string ans(n,' ');
  int k=0;
  rep(i,n){
    if(s[i]=='('){
      k++;
      if(k%2){
        ans[i]='0';
      }else{
        ans[i]='1';
      }
    }else{
      k--;
      if(k%2){
        ans[i]='1';
      }else{
        ans[i]='0';
      }
    }
  }
  cout << ans << endl;
  return 0;
}