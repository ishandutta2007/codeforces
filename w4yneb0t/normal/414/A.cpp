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
in lrg=300000000;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  in n,k;
  cin>>n>>k;
  in ttk=n/2;
  if(ttk>k || (ttk==0 && k>0)){
    cout<<-1<<endl;
    return 0;
  }
  if(n==1){cout<<1<<endl; return 0;}
  cout<<(k-ttk+1)<<" "<<(k-ttk+1)*2;
  forn(i,ttk-1){
    cout<<" "<<lrg+2*i<<" "<<lrg+2*i+1;
  }
  if(n%2)cout<<" "<<2*lrg;
  cout<<"\n";
  return 0;
}