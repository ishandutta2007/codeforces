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
VVI gl;
VVI act;
in tct=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  string tp;
  forn(i,n){
    gl.PB(VI(0));
    cin>>tp;
    forv(j,tp){
      gl[i].PB((tp[j]=='B')*2-1);
    }
  }
  act=gl;
  act.PB(VI(m,0));
  forn(i,n+1)
    act[i].PB(0);
  for(in i=n-1;i>=0;i--){
    for(in j=m-1;j>=0;j--){
      act[i][j]=act[i+1][j]+act[i][j+1]-act[i+1][j+1];
      if(act[i][j]!=gl[i][j])
	tct++;
      act[i][j]=gl[i][j];
    }
  }
  cout<<tct<<endl;
  return 0;
}