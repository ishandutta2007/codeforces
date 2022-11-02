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
string s;
VI cnt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n>>s;
  cnt.resize(300,0);
  forv(i,s)
    ++cnt[s[i]];
  in mx=-1;
  in cc=0;
  forv(i,cnt){
    if(cnt[i]>mx){
      mx=cnt[i];
      cc=0;
    }
    if(cnt[i]==mx)
      ++cc;
  }
  in r=1;
  const in mdl=1000000007LL;
  forn(i,n)
    r=r*cc%mdl;
 cout<<r<<endl;
  return 0;
}