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
VVI bst,bmd;

VI a;
VI rlu,rld;
VI lst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  rlu=rld=VI(n,-1);
  lst=VI(100007,-1);
  forn(i,n){
    rlu[i]=lst[a[i]+1];
    rld[i]=lst[a[i]-1];
    lst[a[i]]=i;
  }
  bst.resize(n);
  bmd.resize(n);
  forn(i,n){
    bst[i].resize(i);
    bmd[i].resize(7);
  }
  VVI bal(n,VI(7,0));
  VVI bdb(7,VI(7,0));
  in clf;
  forn(frnt,n){
    clf=a[frnt]%7;
    forn(i,7)
      bmd[frnt][i]=1;
    in lbu=-1;
    in lbd=-1;
    forn(of,frnt){
      bst[frnt][of]=bmd[of][clf]+1;
      if(lbu!=-1)
	bst[frnt][of]=max(bst[frnt][of],bst[of][lbu]+1);
      if(lbd!=-1)
	bst[frnt][of]=max(bst[frnt][of],bst[of][lbd]+1);
      if(a[of]==a[frnt]+1)
	lbu=of;
      if(a[of]==a[frnt]-1)
	lbd=of;
    }
    in c=rlu[frnt];
    forn(z,2){
      if(c!=-1){
	forn(of,c)
	  bst[frnt][of]=max(bst[frnt][of],bst[c][of]+1);
	forn(i,7)
	  bmd[frnt][i]=max(bmd[frnt][i],bmd[c][i]+1);
      }
      c=rld[frnt];
    }
    forn(i,7)
      bmd[frnt][i]=max(bmd[frnt][i],bdb[clf][i]+1);
    forn(of,frnt){
      bst[frnt][of]=max(bst[frnt][of],bal[of][clf]+1);
    }
    forn(of,frnt){
      bmd[frnt][a[of]%7]=max(bmd[frnt][a[of]%7],bst[frnt][of]);
      bal[of][clf]=max(bal[of][clf],bst[frnt][of]);
    }
    forn(i,7)
      bdb[clf][i]=max(bdb[clf][i],bmd[frnt][i]);
  }
  in tb=0;
  forn(i,n){
    forn(j,i)
      tb=max(tb,bst[i][j]);
    forn(j,7)
      tb=max(tb,bmd[i][j]);
  }
  if(tb==1)
    tb=0;
  cout<<tb<<endl;
  return 0;
}