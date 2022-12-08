#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;

int main(){
  int n;cin>>n;
  string s;
  cin>>s;
  string t="aiueoy";
  bool ok=true;
  rep(i,n){
    bool vowel=false;
    rep(j,6){
      if(s[i]==t[j]){
        vowel=true;
        if(ok){cout<<s[i];ok=false;}
        }
      }
      if(!vowel){
        ok=true;
        cout<<s[i];
        }
    }
  cout<<endl;  
  return 0;
  }