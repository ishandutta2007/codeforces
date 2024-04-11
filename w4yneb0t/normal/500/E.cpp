#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<stack>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n;
vector<in> p,l;
vector<in> pgt;
stack<in> dmn;
map<in,in> pts;
vector<in> pr[20];
vector<in> dtt[20];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  p.resize(n);
  pgt=l=p;
  forn(i,n){
    cin>>p[i]>>l[i];
    pts[p[i]]=i;
  }
  in gt;
  in np=n;
  for(in i=n-1;i>=0;i--){
    gt=p[i]+l[i];
    while(!dmn.empty() && p[dmn.top()]<=gt){
      gt=max(gt,pgt[dmn.top()]);
      dmn.pop();
    }
    pgt[i]=gt;
    if(pts.find(gt)==pts.end()){
      pts[gt]=np++;
      p.PB(gt);
    }
    dmn.push(i);
  }
  forn(i,20){
    pr[i].resize(np);
    dtt[i].resize(np);
  }
  map<in,in>::iterator it2,it;
  for(it=pts.begin();it!=pts.end();++it){
    if(it->second<n){
      pr[0][it->second]=pts[pgt[it->second]];
      dtt[0][it->second]=0;
    }
    else{
      it2=it;
      ++it2;
      if(it2!=pts.end()){
	pr[0][it->second]=it2->second;
	dtt[0][it->second]=it2->first-it->first;
      }
      else{
	pr[0][it->second]=it->second;
	dtt[0][it->second]=0;
      }
    }
  }
  for(in i=1;i<20;i++){
    forn(j,np){
      pr[i][j]=pr[i-1][pr[i-1][j]];
      dtt[i][j]=dtt[i-1][j]+dtt[i-1][pr[i-1][j]];
    }
  }
  in q;
  cin>>q;
  in x,y,sm;
  forn(i,q){
    cin>>x>>y;
    x--;
    y--;
    sm=0;
    for(in i=19;i>=0;i--){
      if(p[pr[i][x]]<=p[y]){
	sm+=dtt[i][x];
	x=pr[i][x];
      }
    }
    if(p[x]<p[y]){
      sm+=dtt[0][x];
      x=pr[0][x];
    }
    cout<<sm<<"\n";
  }
  return 0;
}