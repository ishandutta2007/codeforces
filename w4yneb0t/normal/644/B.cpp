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
VI et,dur;
struct evt{
  in t,typ,id;
  evt(in a=0, in b=0, in c=0){
    t=a;
    typ=b;
    id=c;
  }
  bool operator<(const evt cp)const{
    if(t!=cp.t)
      return t>cp.t;
    return typ>cp.typ;
  }
};
priority_queue<evt> q;
queue<in> qq;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,b;
  cin>>n>>b;
  et.resize(n);
  dur.resize(n);
  in ct;
  forn(i,n){
    cin>>ct>>dur[i];
    q.push(evt(ct,1,i));
  }
  evt tp;
  in inq=0;
  bool busy=0;
  in nq;
  while(!q.empty()){
    tp=q.top();
    q.pop();
    if(tp.typ==0){
      busy=0;
      et[tp.id]=tp.t;
      if(inq){
	busy=1;
	nq=qq.front();
	qq.pop();
	--inq;
	q.push(evt(tp.t+dur[nq],0,nq));
      }
    }
    else{
      if(inq==b){
	et[tp.id]=-1;
	continue;
      }
      if(inq==0 && !busy){
	busy=1;
	q.push(evt(tp.t+dur[tp.id],0,tp.id));
	continue;
      }
      ++inq;
      qq.push(tp.id);
    }
  }
  forv(i,et)
    cout<<et[i]<<" ";
  cout<<"\n";
  return 0;
}