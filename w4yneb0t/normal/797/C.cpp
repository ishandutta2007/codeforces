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
string stk;
string sol;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  in ids=0;
  for(char nxt='a';nxt<='z';++nxt){
    while(sz(stk)>0 && stk.back()<=nxt){
      sol+=stk.back();
      stk.pop_back();
    }
    in lstn=-1;
    for(in i=ids;i<sz(s);++i){
      if(s[i]==nxt)
	lstn=i;
    }
    while(ids<=lstn){
      if(s[ids]==nxt)
	sol+=nxt;
      else
	stk+=s[ids];
      ++ids;
    }
  }
  while(sz(stk)>0){
    sol+=stk.back();
    stk.pop_back();
  }
  cout<<sol<<endl;
  return 0;
}