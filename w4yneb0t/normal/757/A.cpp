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
string gl="Bulbasaur";
string hv;
VI hgl;
VI htt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  hgl.resize(300);
  htt.resize(300);
  cin>>hv;
  forv(i,gl)
    ++hgl[gl[i]];
  forv(i,hv)
    ++htt[hv[i]];
  in mn=1e9;
  forv(i,hgl){
    if(hgl[i]){
      mn=min(mn,htt[i]/hgl[i]);
    }
  }
  cout<<mn<<endl;
  return 0;
}