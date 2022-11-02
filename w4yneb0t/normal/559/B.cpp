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
string cann(const string& s){
  in n=sz(s);
  if(n%2)
    return s;
  string c1=s.substr(0,n/2);
  string c2=s.substr(n/2,n/2);
  c1=cann(c1);
  c2=cann(c2);
  if(c2<c1)
    swap(c1,c2);
  return c1+c2;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a,b;
  cin>>a>>b;
  a=cann(a);
  b=cann(b);
  cout<<(a==b?"YES":"NO")<<endl;
  return 0;
}