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
in n;
VI t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  t.resize(n);
  forn(i,n)
    cin>>t[i];
  sort(all(t));
  in bt=0;
  in ssf=0;
  forv(i,t){
    if(t[i]>=ssf){
      bt++;
      ssf+=t[i];
    }
  }
  cout<<bt<<endl;
  return 0;
}