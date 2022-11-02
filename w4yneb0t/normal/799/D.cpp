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
const in inf=1e9;
in bst=inf;
in a,b;
VI ext;
void proc(in h, in w, in nxt){
  if(h>w)
    swap(h,w);
  if(w>=b && h>=a){
    bst=min(bst,nxt);
    return;
  }
  if(nxt==sz(ext))
    return;
  if(ext[nxt]==2){
    if(h<a)
      proc(h*2,w,nxt+1);
    else
      proc(h,w*2,nxt+1);
  }
  else{
    if(h<a)
      proc(h*ext[nxt],w,nxt+1);
    if(w<b)
      proc(w*ext[nxt],h,nxt+1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in h,w,n;
  cin>>a>>b>>h>>w>>n;
  if(a>b)
    swap(a,b);
  ext.resize(n);
  forn(i,n)
    cin>>ext[i];
  sort(all(ext));
  reverse(all(ext));
  proc(h,w,0);
  if(bst==inf)
    cout<<-1<<endl;
  else
    cout<<bst<<endl;
  return 0;
}