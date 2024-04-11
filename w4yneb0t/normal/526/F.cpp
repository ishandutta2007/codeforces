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
in n;
in sm=0;
VI rof,cof;
VI mlef,mrit;
VI vst;
queue<in> q;
vector<pair<in,in> > loc;
void gg(in a, in b){
  if(b<a)return;
  in mid=(a+b)/2;
  gg(a,mid-1);gg(mid+1,b);
  for(in i=a;i<=b;i++)
    vst[i]=0;
  in u,v;
  for(in i=a;i<=mid;i++){
    if(vst[i])continue;
    vst[i]=1;
    mlef[i]=i;
    q.push(i);
    while(!q.empty()){
      u=q.front();
      q.pop();
      v=u+1;
      if(u<mid)v=u-1;
      if(v>=a && v<=b && !vst[v]){
	vst[v]=1;
	q.push(v);
	mlef[v]=mlef[u];
      }
      if(rof[u]<rof[mid] && rof[u]!=0)
	v=cof[rof[u]-1];
      if(rof[u]>rof[mid] && rof[u]!=n-1)
	v=cof[rof[u]+1];
      if(v>=a && v<=b && !vst[v]){
	vst[v]=1;
	q.push(v);
	mlef[v]=mlef[u];
      }
    }
  }
  for(in i=a;i<=b;i++)
    vst[i]=0;
  for(in i=b;i>=mid;i--){
    if(vst[i])continue;
    vst[i]=1;
    mrit[i]=i;
    q.push(i);
    while(!q.empty()){
      u=q.front();
      q.pop();
      v=u+1;
      if(u<=mid)v=u-1;
      if(v>=a && v<=b && !vst[v]){
	vst[v]=1;
	q.push(v);
	mrit[v]=mrit[u];
      }
      if(rof[u]<rof[mid] && rof[u]!=0)
	v=cof[rof[u]-1];
      if(rof[u]>rof[mid] && rof[u]!=n-1)
	v=cof[rof[u]+1];
      if(v>=a && v<=b && !vst[v]){
	vst[v]=1;
	q.push(v);
	mrit[v]=mrit[u];
      }
    }
  }
  for(in i=a;i<=b;i++)
    vst[i]=0;
  for(in i=a;i<=b;i++){
    if(vst[i])continue;
    if(!((rof[i]<rof[mid] && (cof[rof[i]+1]<a || cof[rof[i]+1]>b))||(rof[i]>rof[mid] && (cof[rof[i]-1]<a || cof[rof[i]-1]>b))))continue;
    vst[i]=1;
    mlef[i]=a-1;
    q.push(i);
    while(!q.empty()){
      u=q.front();
      q.pop();
      if(u==mid)continue;
      v=u+1;
      if(u<mid)v=u-1;
      if(v>=a && v<=b && !vst[v]){
	vst[v]=1;
	q.push(v);
	mlef[v]=mlef[u];
      }
      if(rof[u]<rof[mid] && rof[u]!=0)
	v=cof[rof[u]-1];
      if(rof[u]>rof[mid] && rof[u]!=n-1)
	v=cof[rof[u]+1];
      if(v>=a && v<=b && !vst[v]){
	vst[v]=1;
	q.push(v);
	mlef[v]=mlef[u];
      }
    }
  }
  loc.clear();
  v=b;
  for(in i=a;i<=mid;i++){
    if(mlef[i]<i)continue;
    u=mrit[i];
    while(mlef[v]<i)--v;
    if(v>=u){
      loc.PB(MP(v,1));
      loc.PB(MP(u-1,-1));
    }
  }
  in cs=0;
  sort(all(loc));
  reverse(all(loc));
  v=0;
  for(in i=b;i>=mid;i--){
    while(v<sz(loc) && loc[v].first>=i){
      cs+=loc[v].second;
      ++v;
    }
    if(mrit[i]<=i)sm+=cs;
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  mlef.resize(n);
  mrit.resize(n);
  rof.resize(n);
  cof.resize(n);
  vst.resize(n);
  in ta,tb;
  forn(i,n){
    cin>>ta>>tb;
    ta--;
    tb--;
    rof[ta]=tb;
    cof[tb]=ta;
  }
  gg(0,n-1);
  cout<<sm<<endl;
  return 0;
}