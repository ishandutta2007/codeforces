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
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  CFS;
  int n;
  cin >> n;
  string s,t;
  rep(q,n){
    cin >> s >> t;
    if(s[0]!=t[0]){
      cout << "NO" << endl;
      continue;
    }
    char pre='A';
    int now=0;
    for(int i=0;i<s.length();i++){
      if(s[i]!=pre){
        while(now<t.length()){
          if(pre!=t[now]) break;
          now++;
        }
      }
      if(now==t.length()){
        cout << "NO" << endl;
        goto next;
      }
      if(s[i]!=t[now]){
        cout << "NO" << endl;
        goto next;
      }
      now++;
      pre=s[i];
    }
    while(now<t.length()){
      if(pre!=t[now]) break;
      now++;
    }
    if(now==t.length()) cout << "YES" << endl;
    else cout << "NO" << endl;
    next:;
  }
  return 0;
}