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
map<in,in> vtp;
struct unifnd{
  VI ht,pr;
  in fnd(in a){
    in ta=a;
    while(a!=pr[a])a=pr[a];
    in tt=ta;
    while(ta!=a){
      tt=pr[ta];
      pr[ta]=a;
      ta=tt;
    }
    return a;
  }
  void uni(in a, in b){
    a=fnd(a);
    b=fnd(b);
    if(a==b)return;
    if(ht[b]<ht[a])swap(a,b);
    pr[a]=b;
    ht[b]+=(ht[a]==ht[b]);
  }
  void ini(in n){
    ht.resize(n);
    pr.resize(n);
    forn(i,n){
      ht[i]=0;
      pr[i]=i;
    }
  }
};
unifnd tfd;
VI a;
map<in,VI> seq;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  tfd.ini(n);
  a.resize(n);
  forn(i,n){
    cin>>a[i];
    vtp[a[i]];
  }
  in nxt=0;
  fors(i,vtp)
    i->second=nxt++;
  forn(i,n)
    tfd.uni(i,vtp[a[i]]);
  forn(i,n)
    seq[tfd.fnd(i)].PB(i+1);
  cout<<sz(seq)<<"\n";
  fors(i,seq){
    cout<<sz(i->second);
    forv(j,i->second)
      cout<<" "<<i->second[j];
    cout<<"\n";
  }
  return 0;
}