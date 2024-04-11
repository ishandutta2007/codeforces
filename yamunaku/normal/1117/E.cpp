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
  string s;
  cin >> s;
  int n=s.length();
  vector<string> ret(3);
  cout << "? ";
  for(int i=0;i<n;i++){
    cout << (char)(i/676+'a');
  }
  cout << endl;
  cin >> ret[0];
  cout << "? ";
  for(int i=0;i<n;i++){
    cout << (char)(i%676/26+'a');
  }
  cout << endl;
  cin >> ret[1];
  cout << "? ";
  for(int i=0;i<n;i++){
    cout << (char)(i%26+'a');
  }
  cout << endl;
  cin >> ret[2];
  string ans(n,'a');
  for(int i=0;i<n;i++){
    int idx=(ret[0][i]-'a')*676+(ret[1][i]-'a')*26+(ret[2][i]-'a');
    ans[idx]=s[i];
  }
  cout << "! " << ans << endl;
  return 0;
}