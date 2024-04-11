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
  string s;
  cin >> s;
  vector<int> ans(s.length(),0);
  int now=0;
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]-'a'==now){
      ans[i]=1;
      now=1-now;
    }
  }
  for(int i=0;i<s.length();i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}