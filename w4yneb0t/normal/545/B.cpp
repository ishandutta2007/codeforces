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
string s,t,r;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>s>>t;
  in nx=0;
  forv(i,s){
    if(s[i]==t[i])
      r.PB('0');
    else
      r.PB('0'+((nx++)+(s[i]-'0'))%2);
  }
  cout<<(nx%2==1?"impossible":r)<<endl;
  return 0;
}