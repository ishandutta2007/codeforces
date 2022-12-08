#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 510101010;
const int mod=1e9+7;
const ll longinf=1LL<<60;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  int cnt=0;
  rep(i,n){
    if(s[i]-'a'<=cnt){
      s[i]=cnt+'a';
      cnt++;
      }
    if(cnt==26)break;
    }
  if(cnt<26)cout<<-1<<endl;
  else cout<<s<<endl;
  return 0;
  }