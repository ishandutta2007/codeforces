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
set<in> ss;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  ss.insert(0);
  ss.insert(n+1);
  char c;
  forn(i,n){
    cin>>c;
    if(c!='.')
      ss.insert(i+1);
  }
  in ttl=0;
  in prv=0;
  fors(i,ss){
    if(*i-prv>2)
      ttl+=*i-prv-2;
    prv=*i;
  }
  in ta;
  set<in>::iterator it1,it2;
  forn(z,m){
    cin>>ta>>c;
    if(c!='.'){
      if(ss.count(ta)){
	cout<<ttl<<"\n";
	continue;
      }
      it1=ss.lower_bound(ta);
      it2=it1;
      --it1;
      if(*it2-*it1>2)
	ttl-=*it2-*it1-2;
      if(*it2-ta>2)
	ttl+=*it2-ta-2;
      if(ta-*it1>2)
	ttl+=ta-*it1-2;
      ss.insert(ta);
    }
    else{
      if(!ss.count(ta)){
	cout<<ttl<<"\n";
	continue;
      }
      ss.erase(ta);
      it1=ss.lower_bound(ta);
      it2=it1;
      --it1;
      if(*it2-*it1>2)
	ttl+=*it2-*it1-2;
      if(*it2-ta>2)
	ttl-=*it2-ta-2;
      if(ta-*it1>2)
	ttl-=ta-*it1-2;
    }
    cout<<ttl<<"\n";
  }
  return 0;
}