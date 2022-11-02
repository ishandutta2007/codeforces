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
vector<in> p;
in n;
vector<in> pr,ht;
in fnd(in a){
  in t=a;
  in ta;
  while(a!=pr[a]){
    a=pr[a];
  }
  while(t!=a){
    ta=pr[t];
    pr[t]=a;
    t=ta;
  }
  return a;
}
void uni(in a, in b){
  a=fnd(a);
  b=fnd(b);
  if(a==b)return;
  if(ht[a]>ht[b]){uni(b,a);return;}
  ht[b]+=(ht[a]==ht[b]);
  pr[a]=b;
}
vector<vector<in> > a;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  p.resize(n);
  pr.resize(n);
  ht.resize(n);
  forn(i,n){
    cin>>p[i];
    pr[i]=i;
    ht[i]=0;
  }
  string tp;
  forn(i,n){
    cin>>tp;
    forn(j,n){
      if(tp[j]=='1')
	uni(i,j);
    }
  }
  forn(i,n){
    in mid=i;
    for(in j=i+1;j<n;j++){
      if(fnd(j)==fnd(i) && p[j]<p[mid])
	mid=j;
    }
    if(mid!=i)
      swap(p[mid],p[i]);
    cout<<p[i]<<" ";
  }
  cout<<endl;
  return 0;
}