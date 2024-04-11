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
void mrk(in a, in b, string s, in c){
  cout<<a<<" "<<s<<" "<<b<<" = "<<c<<"\n";
}
void opt(in n){
  if(n>5){
    mrk(n,n-1,"-",1);
    mrk(1,2,"*",2);
    opt(n-2);
    return;
  }
  if(n==4){
    mrk(1,2,"*",2);
    mrk(2,3,"*",6);
    mrk(6,4,"*",24);
  }
  if(n==5){
    mrk(5,4,"*",20);
    mrk(20,3,"+",23);
    mrk(23,2,"+",25);
    mrk(25,1,"-",24);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  if(n<=3){
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  opt(n);
  return 0;
}