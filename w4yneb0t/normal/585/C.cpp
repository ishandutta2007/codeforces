#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<sstream>
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
void imp(){
  cout<<"Impossible"<<endl;
  exit(0);
}
string sof(in a){
  stringstream s;
  s<<a;
  string r;
  s>>r;
  return r;
}
string sol(in x, in y){
  if(x==y){
    if(x!=1)
      imp();
    return "";
  }
  if(x>y){
    string c=sol(y,x);
    forv(i,c){
      if(c[i]=='A' || c[i]=='B')
	c[i]=char(in('A')+in('B')-in(c[i]));
    }
    return c;
  }
  in tm=(y-1)/x;
  in rs=y-x*tm;
  return sof(tm)+'B'+sol(x,rs);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in x,y;
  cin>>x>>y;
  cout<<sol(x,y)<<endl;
  return 0;
}