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
VI vis;
void gen(in& f, in &p, in h, in a, in x, in y){
  vis=VI(1000009,-1);
  in ct=0;
  while(vis[h]==-1){
    vis[h]=ct;
    h=(x*h+y)%mdl;
    ++ct;
  }
  if(vis[a]==-1){
    cout<<-1<<endl;
    exit(0);
  }
  f=vis[a];
  p=ct-vis[h];
  if(vis[a]<vis[h])
    p=-1;
}
in f1,p1,f2,p2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>mdl;
  in h1,a1,x1,y1;
  cin>>h1>>a1>>x1>>y1;
  gen(f1,p1,h1,a1,x1,y1);
  cin>>h1>>a1>>x1>>y1;
  gen(f2,p2,h1,a1,x1,y1);
  in c1=f1;
  in rth=f1%p2;
  in trs=0;
  in r2=f2%p2;
  in radd=p1%p2;
  if(p2==-1){
    swap(f1,f2);
    swap(p1,p2);
  }
  if(p1==-1){
    if(p2==-1){
      if(f1==f2)
	cout<<f1<<endl;
      else
	cout<<-1<<endl;
      return 0;
    }
    if(f1>=f2 && f1%p2==f2%p2)
      cout<<f1<<endl;
    else
      cout<<-1<<endl;
    return 0;
  }
  while(trs<2000009 && (c1<f2 || rth!=r2)){
    ++trs;
    c1+=p1;
    rth+=radd;
    if(rth>=p2)rth-=p2;
  }
  if(c1>=f2 && rth==r2)
    cout<<c1<<endl;
  else
    cout<<-1<<endl;
  return 0;
}