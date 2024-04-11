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
in n,m,k;
vector<vector<in> > a;
in best;
void tres(vector<in> att){
  in sf=0;
  forn(i,n){
    in mm=0;
    forn(j,m)
      mm+=(a[i][j]!=att[j]);
    if(mm<m-mm)
      sf+=mm;
    else
      sf+=m-mm;
  }
  if(sf<best)
    best=sf;
}
in p2(in c){
  return (1LL<<c);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m>>k;
  best=k+1;
  a.resize(n,vector<in>(m));
  forn(i,n)
    forn(j,m)
    cin>>a[i][j];
  if(n<=k){
    vector<vector<in> > tpa;
    tpa.resize(m,vector<in>(n));
    forn(i,n)
      forn(j,m)
      tpa[j][i]=a[i][j];
    a=tpa;
    swap(n,m);
  }
  if(n<=k){
    forn(msk,p2(m)){
      vector<in> att(0);
      forn(i,m){
	if(msk&p2(i))
	  att.PB(1);
	else
	  att.PB(0);
      }
      tres(att);
    }
  }
  else{
    forn(i,n){
      vector<in> att(0);
      forn(j,m){
	att.PB(a[i][j]);
      }
      tres(att);
    }
  }
  if(best==k+1)
    cout<<-1<<endl;
  else
    cout<<best<<endl;
  return 0;
}