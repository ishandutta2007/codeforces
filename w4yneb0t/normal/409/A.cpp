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
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
bool bts(char a, char b){
  if(a=='8' && b=='[')
    return 1;
  if(a=='[' && b=='(')
    return 1;
  if(a=='(' && b=='8')
    return 1;
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string t1,t2;
  cin>>t1>>t2;
  in sc=0;
  for(in i=0;i<t1.length();i+=2){
    sc+=bts(t1[i],t2[i]);
    sc-=bts(t2[i],t1[i]);
  }
  if(sc>0)
    cout<<"TEAM 1 WINS";
  if(sc==0)
    cout<<"TIE";
  if(sc<0)
    cout<<"TEAM 2 WINS";
  cout<<endl;
  return 0;
}