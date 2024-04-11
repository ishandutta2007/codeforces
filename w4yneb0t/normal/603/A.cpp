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
string ts;
VI s;
vector<VVI> bst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cin>>ts;
  forv(i,ts)
    s.PB(ts[i]-'0');
  bst.resize(2,VVI(3,VI(n,0)));
  forn(k,3)
    bst[s[0]][k][0]=1;
  in totres=1;
  for(in i=1;i<sz(s);++i){
    bst[!s[i]][0][i]=bst[!s[i]][0][i-1];
    bst[s[i]][0][i]=bst[!s[i]][0][i-1]+1;
    forn(k,2)
      bst[!s[i]][1][i]=max(bst[!s[i]][1][i],bst[s[i]][k][i-1]+1);
    bst[s[i]][1][i]=bst[s[i]][1][i-1];
    forn(k,3)
      bst[s[i]][2][i]=max(bst[s[i]][2][i],bst[!s[i]][k][i-1]+1);
    bst[!s[i]][2][i]=bst[!s[i]][2][i-1];
  }
  forn(j,2)
    forn(k,3)
    forn(i,n)
    totres=max(totres,bst[j][k][i]);
  cout<<totres<<endl;
  return 0;
}