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
const in mx=1009;
in n,m,k;
string s,t;
in sml[mx][mx];
in bst[mx][mx][12];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  cin>>s>>t;
  forn(i,n+1)
    sml[i][m]=0;
  forn(i,m+1)
    sml[n][i]=0;
  for(in i=n-1;i>=0;--i){
    for(in j=m-1;j>=0;--j){
      if(s[i]!=t[j])
	sml[i][j]=0;
      else
	sml[i][j]=sml[i+1][j+1]+1;
      for(in z=1;z<=k;++z){
	bst[i][j][z]=max(bst[i+1][j][z],bst[i][j+1][z]);
	if(s[i]==t[j])
	  bst[i][j][z]=max(bst[i][j][z],bst[i+sml[i][j]][j+sml[i][j]][z-1]+sml[i][j]);
      }
    }
  }
  cout<<bst[0][0][k]<<endl;
  return 0;
}