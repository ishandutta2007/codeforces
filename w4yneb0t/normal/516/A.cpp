#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
vector<string> enc={"","","2","3","322","5","53","7","7222","7332"};
string res;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  string s;
  cin>>n>>s;
  forv(i,s)
    res+=enc[s[i]-'0'];
  sort(all(res));
  reverse(all(res));
  cout<<res<<endl;
  return 0;
}