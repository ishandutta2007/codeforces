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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI sol;
VI v,d,k;
queue<in> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  v.resize(n);
  d.resize(n);
  k.resize(n);
  forn(i,n)
    cin>>v[i]>>d[i]>>k[i];
  forn(i,n){
    if(k[i]<0)
      continue;
    sol.PB(i+1);
    in r=v[i]+1;
    for(in j=i+1;j<n;++j){
      if(k[j]<0)
	continue;
      --r;
      if(r<=0)
	break;
      k[j]-=r;
      if(k[j]<0)
	q.push(j);
    }
    in j;
    while(!q.empty()){
      j=q.front();
      q.pop();
      for(in s=j+1;s<n;++s){
	if(k[s]>=0){
	  k[s]-=d[j];
	  if(k[s]<0)
	    q.push(s);
	}
      }
    }
  }
  cout<<sz(sol)<<endl;
  forv(i,sol)
    cout<<sol[i]<<" ";
  cout<<endl;
  return 0;
}