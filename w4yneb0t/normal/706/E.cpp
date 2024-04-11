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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VVI opt;
VI nr,nd;
in fd(in a, in b){
  in c=0;
  forn(i,a)
    c=nd[c];
  forn(i,b)
    c=nr[c];
  return c;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,q;
  cin>>n>>m>>q;
  opt.resize(n+1,VI(m+1));
  forn(i,n){
    forn(j,m){
      cin>>opt[i+1][j+1];
    }
  }
  nr=nd=VI((n+1)*(m+1));
  forn(i,n+1){
    forn(j,m+1){
      nr[i*(m+1)+j]=i*(m+1)+j+1;
      if(j==m)
	nr[i*(m+1)+j]=-1;
      nd[i*(m+1)+j]=(i+1)*(m+1)+j;
      if(i==n)
	nd[i*(m+1)+j]=-1;
    }
  }
  in a,b,c,d,h,w;
  in tpl,tpr;
  forn(z,q){
    cin>>a>>b>>c>>d>>h>>w;
    in t1=fd(a-1,b-1);
    in t2=fd(c-1,d-1);
    in ta=nr[t1];
    in tb=nr[t2];
    forn(z,w){
      if(z==w-1){
	tpl=nd[ta];
	tpr=nd[tb];
      }
      swap(nd[ta],nd[tb]);
      ta=nr[ta];
      tb=nr[tb];
    }
    ta=nd[t1];
    tb=nd[t2];
    forn(z,h){
      swap(nr[tpl],nr[tpr]);
      tpl=nd[tpl];
      tpr=nd[tpr];
      if(z==h-1){
	tpl=nr[ta];
	tpr=nr[tb];
      }
      swap(nr[ta],nr[tb]);
      ta=nd[ta];
      tb=nd[tb];
    }
    forn(z,w){
      swap(nd[tpl],nd[tpr]);
      tpl=nr[tpl];
      tpr=nr[tpr];
    }
  }
  in cc=nr[nd[0]];
  forn(i,n){
    c=cc;
    forn(j,m){
      cout<<opt[c/(m+1)][c%(m+1)]<<" ";
      c=nr[c];
    }
    cout<<"\n";
    cc=nd[cc];
  }
  return 0;
}