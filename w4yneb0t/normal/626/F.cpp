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
const in mdl=1000000007LL;
const in mx=109;
VI mar;
in n,k;
VVI wys[2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  sort(all(mar));
  forn(z,2)
    wys[z].resize(mx,VI(k+9,0));
  in sw=1;
  in nw=0;
  wys[nw][0][0]=1;
  in nxtstu=0;
  in curval=0;
  while(nxtstu<n){
    swap(sw,nw);
    forn(i,mx){
      forn(j,k+9){
	wys[nw][i][j]=0;
	wys[sw][i][j]%=mdl;
      }
    }
    if(mar[nxtstu]>curval){
      forn(i,mx){
	forn(j,k+9-i)
	  wys[nw][i][j+i]+=wys[sw][i][j];
      }
      ++curval;
      continue;
    }
    forn(i,mx-3){
      forn(j,k+5){
	wys[nw][i+1][j]+=wys[sw][i][j];
	if(i)
	  wys[nw][i-1][j]+=wys[sw][i][j]*i;
	wys[nw][i][j]+=wys[sw][i][j]*(i+1);
      }
    }
    ++nxtstu;
  }
  in totv=0;
  forn(i,k+1)
    totv+=wys[nw][0][i]%mdl;
  totv%=mdl;
  cout<<totv<<endl;
  return 0;
}