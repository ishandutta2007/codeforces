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
  int n;
  cin >> n;
  string s;
  vector<int> l(500001,0),r(500001,0);
  int p;
  bool sei=false,hu=false;
  for(int i=0;i<n;i++){
    sei=false,hu=false;
    cin >> s;
    p=0;
    for(int j=0;j<s.length();j++){
      if(s[j]=='('){
        p++;
      }else{
        p--;
        if(p<0) hu=true;
      }
    }
    if(!hu){
      l[p]++;
    }else{
      p=0;
      for(int j=s.length()-1;j>=0;j--){
        if(s[j]=='('){
          p--;
          if(p<0) sei=true;
        }else{
          p++;
        }
      }
      if(!sei){
        r[p]++;
      }
    }
  }
  int ans=l[0]/2;
  for(int i=1;i<=500000;i++){
    ans+=min(l[i],r[i]);
  }
  cout << ans << endl;
  return 0;
}