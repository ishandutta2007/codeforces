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
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n,m;
struct pt{
  in x,y;
};
vector<pt> pts;
map<in,map<in, in> > vertm,horm;
queue<pt> q;
vector<int> seen;
void adp(map<in, map<in,in> >& mp, in a, in b, in dir){
  if(mp.find(a)==mp.end())
    return;
  map<in,in>& tp=mp[a];
  map<in,in>::iterator it1,it2;
  bool ntr=(tp.find(b)==tp.end());
  if(ntr)
    tp[b]=0;
  else{
    in tt=tp[b];
    if(seen[tt])
      return;
    q.push(pts[tt]);
    seen[tt]=1;
  }
  it1=tp.find(b);
  it2=it1;
  while(1){
    if(dir==-1 && it2==tp.begin())
      break;
    if(dir==1)
      it2++;
    else
      it2--;
    if(it2==tp.end())
      break;
    in tt=it2->second;
    if(seen[tt])
      break;
    seen[tt]=1;
    q.push(pts[tt]);
  }
  if(ntr)
    tp.erase(it1);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m;
  pts.resize(m);
  seen.resize(m);
  forn(i,m){
    cin>>pts[i].x>>pts[i].y;
    if(pts[i].x==n && pts[i].y==n){
      cout<<"-1"<<endl;
      return 0;
    }
    if(pts[i].x==1 || pts[i].y==n){
      seen[i]=1;
      q.push(pts[i]);
      continue;
    }
    vertm[pts[i].y][pts[i].x]=i;
    horm[pts[i].x][pts[i].y]=i;
  }
  pt tp;
  while(!q.empty()){
    tp=q.front();
    q.pop();
    if(tp.x==n || tp.y==1){
      cout<<"-1"<<endl;
      return 0;
    }
    adp(vertm,tp.y-1,tp.x+1,-1);
    adp(horm,tp.x+1,tp.y-1,1);
  }
  cout<<2*(n-1)<<endl;
  return 0;
}