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
in af(in x, in y){
  ++x;
  ++y;
  cout<<"1 "<<x<<" "<<y<<endl;
  string r;
  cin>>r;
  if(r=="TAK")
    return 1;
  if(r=="NIE")
    return 0;
  assert(0);
  return 0;
}
void opt(in x, in y){
  ++x;
  ++y;
  cout<<"2 "<<x<<" "<<y<<endl;
  exit(0);
}
in fd(in l, in r){
  if(l>r)
    return -10;
  if(l==r)
    return l;
  in lt=(r-l+1);
  in x=(lt-1)/2+l;
  in y=x+1;
  if(af(x,y))
    return fd(l,x);
  return fd(y,r);
}
in n,k;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  in c=fd(0,n-1);
  in al=fd(0,c-1);
  in ar=fd(c+1,n-1);
  if(c==0)
    opt(c,ar);
  if(c==n-1)
    opt(c,al);
  if(af(al,ar))
    opt(c,al);
  opt(c,ar);
  return 0;
}