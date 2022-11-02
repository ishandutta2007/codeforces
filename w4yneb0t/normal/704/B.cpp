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
VI x,a,b,c,d;
VI bst[2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,s,e;
  cin>>n>>s>>e;
  --s;
  --e;
  x.resize(n);
  a.resize(n);
  b.resize(n);
  c.resize(n);
  d.resize(n);
  forn(i,n)
    cin>>x[i];
  forn(i,n)
    cin>>a[i];
  forn(i,n)
    cin>>b[i];
  forn(i,n)
    cin>>c[i];
  forn(i,n)
    cin>>d[i];
  if(s>e){
    s=n-1-s;
    e=n-1-e;
    swap(c,d);
    swap(b,a);
    reverse(all(x));
    reverse(all(a));
    reverse(all(b));
    reverse(all(c));
    reverse(all(d));
    forn(i,n)
      x[i]=1000000005-x[i];
  }
  x.PB(1000000009);
  const in inf=1e15;
  in mx=n/2+9;
  forn(z,2)
    bst[z].resize(mx,inf);
  in sw=1;
  in nw=0;
  bst[nw][0]=0;
  forn(i,n){
    swap(sw,nw);
    forn(j,mx)
      bst[nw][j]=inf;
    if(i!=s && i!=e){
      forn(j,mx-4){
	bst[nw][j+1]=min(bst[nw][j+1],bst[sw][j]+d[i]+b[i]);
	if((j+(i>s && i<e))>0)
	  bst[nw][j]=min(bst[nw][j],bst[sw][j]+d[i]+a[i]);
	if(j>0)
	  bst[nw][j]=min(bst[nw][j],bst[sw][j]+c[i]+b[i]);
	if(j>0)
	  bst[nw][j-1]=min(bst[nw][j-1],bst[sw][j]+c[i]+a[i]);
      }
    }
    if(i==s){
      forn(j,mx-4){
	if(j>0)
	  bst[nw][j-1]=min(bst[nw][j-1],bst[sw][j]+c[i]);
	bst[nw][j]=min(bst[nw][j],bst[sw][j]+d[i]);
      }
    }
    if(i==e){
      forn(j,mx-4){
	bst[nw][j+1]=min(bst[nw][j+1],bst[sw][j]+b[i]);
	bst[nw][j]=min(bst[nw][j],bst[sw][j]+a[i]);
      }
    }
    forn(j,mx)
      bst[nw][j]+=(x[i+1]-x[i])*(2*j+(i>=s && i<e));
    if(i<s || (i>=e && i!=n-1))
      bst[nw][0]=inf;
  }
  cout<<bst[nw][0]<<endl;
  return 0;
}