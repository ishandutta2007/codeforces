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
in mdl;
in dsm(in a){
  in r=0;
  while(a){
    r+=a%10;
    a/=10;
  }
  return r;
}
in tsm(in mx){
  if(mx==0)
    return 0;
  if(mx%10!=9)
    return dsm(mx)+tsm(mx-1);
  in ls=mx/10;
  return tsm(ls)*10+(ls+1)*45;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>mdl;
  in mn=1;
  in mx=1;
  in md;
  while(tsm(mx)<=mdl)
    mx*=2;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(tsm(md)<=mdl)
      mn=md;
    else
      mx=md;
  }
  in b=mx;
  in a=0;
  in sa=tsm(a)%mdl;
  in sb=tsm(b)%mdl;
  while(sa!=sb){
    if(a+1==b || sb<sa){
      b++;
      sb+=dsm(b);
      sb%=mdl;
    }
    else{
      a++;
      sa+=dsm(a);
      sa%=mdl;
    }
  }
  cout<<a+1<<" "<<b<<endl;
  return 0;
}