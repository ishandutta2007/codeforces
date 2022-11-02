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
bool islp(in y){
  if(y%400==0)
    return 1;
  if(y%100!=0 && y%4==0)
    return 1;
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in y;
  cin>>y;
  in tt=0;
  bool lst=islp(y);
  bool lcr=0;
  do{
    tt+=365+islp(y);
    ++y;
    tt%=7;
    lcr=islp(y);
  }while(tt || (lcr!=lst));
  cout<<y<<endl;
  return 0;
}