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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,a,b;
  cin>>n>>a>>b;
  if(a*b<n){
    cout<<-1<<"\n";
    return 0;
  }
  VI nn={-1,0};
  in c;
  forn(i,a){
    forn(j,b){
      c=(i+j)%2;
      if(nn[c]+2>n)
	cout<<0;
      else
	cout<<(nn[c]+=2);
      cout<<" ";
    }
    cout<<"\n";
  }
  return 0;
}