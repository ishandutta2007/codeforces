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
VI l,r;
in sm=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string tl,tr;
  cin>>tl>>tr;
  while(sz(tl)<sz(tr))
    tl="0"+tl;
  while(sz(tl)>0 && tl[0]==tr[0]){
    tl=tl.substr(1,sz(tl)-1);
    tr=tr.substr(1,sz(tr)-1);
  }
  if(sz(tl)==0){
    cout<<1<<endl;
    return 0;
  }
  forv(i,tl){
    l.PB(tl[i]-'0');
    r.PB(tr[i]-'0');
  }
  in nsz=sz(l);
  VI nbr;
  forn(i,nsz)
    nbr.PB(1);
  forn(i,9)
    nbr.PB(0);
  in nbs=sz(nbr);
  sort(all(nbr));
  VI dct(10,0);
  VI rdct(10);
  in cd;
  bool ok;
  in bst;
  do{
    forn(i,10)
      dct[i]=0;
    cd=0;
    forn(i,nbs){
      if(nbr[i]==1){
	++dct[cd];
      }
      else
	++cd;
    }
    ok=0;
    for(in j=l[0]+1;j<r[0];++j){
      if(dct[j]){
	ok=1;
	break;
      }
    }
    if(ok){
      ++sm;
      continue;
    }
    forn(i,10)
      rdct[i]=dct[i];
    bst=9;
    while(bst>=0 && dct[bst]==0)
      --bst;
    forn(i,nsz){
      if(!dct[l[i]])
	break;
      --dct[l[i]];
      while(bst>=0 && dct[bst]==0)
	--bst;
      if(i==nsz-1){
	ok=1;
	break;
      }
      if(bst>l[i+1]){
	ok=1;
	break;
      }
      if(ok)
	break;
    }
    if(ok){
      ++sm;
      continue;
    }
    forn(i,10)
      dct[i]=rdct[i];
    bst=0;
    while(bst<=9 && dct[bst]==0)
      ++bst;
    forn(i,nsz){
      if(ok)
	break;
      if(!dct[r[i]])
	break;
      --dct[r[i]];
      while(bst<=9 && dct[bst]==0)
	++bst;
      if(i==nsz-1){
	ok=1;
	break;
      }
      if(bst<r[i+1]){
	ok=1;
	break;
      }
      if(ok)
	break;
    }
    if(ok){
      ++sm;
      continue;
    }
  }while(next_permutation(all(nbr)));
  cout<<sm<<endl;
  return 0;
}