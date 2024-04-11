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
void fail(){
  cout<<-1<<endl;
  exit(0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  in tct=0;
  cin>>s;
  in lst=-1;
  forv(i,s){
    if(s[i]=='(')
      tct++;
    else
      tct--;
    if(tct<0)
      fail();
    if(s[i]=='#')
      lst=i;
  }
  in rpl=tct;
  tct=0;
  forv(i,s){
    if(s[i]=='(')
      tct++;
    else
      tct--;
    if(i==lst)
      tct-=rpl;
    if(tct<0)
      fail();
  }
  forv(i,s){
    if(s[i]=='#'){
      if(i==lst)
	cout<<rpl+1<<"\n";
      else
	cout<<1<<"\n";
    }
  }
  return 0;
}