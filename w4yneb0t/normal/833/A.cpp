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
VI nfc;
const in tmx=1e6+9;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  nfc.resize(tmx);
  for(in i=2;i<tmx;++i){
    if(nfc[i]==0){
      for(in j=i;j<tmx;j+=i){
	nfc[j]=i;
      }
    }
  }
  in t;
  cin>>t;
  in a,b;
  in cb,mn,mx,md;
  in c1,c2;
  forn(zz,t){
    cin>>a>>b;
    cb=a*b;
    mn=1;
    mx=tmx;
    while(mx-mn>1){
      md=(mx+mn)/2;
      if(md*md*md>cb)
	mx=md;
      else
	mn=md;
    }
    if(mn*mn*mn!=cb){
      cout<<"No\n";
      continue;
    }
    bool bd=0;
    in rm=mn;
    in fc;
    while(rm>1){
      fc=nfc[rm];
      rm/=fc;
      c1=c2=0;
      while(a%fc==0){
	a/=fc;
	++c1;
      }
      while(b%fc==0){
	b/=fc;
	++c2;
      }
      if(c1>2*c2 || c2>2*c1){
	cout<<"No\n";
	bd=1;
	break;
      }
    }
    if(!bd){
      assert(a==1 && b==1);
      cout<<"Yes\n";
    }
  }
  return 0;
}