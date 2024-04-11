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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in mxd=310;
VVI d={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
VVI fld;
vector<VVI> avt;
queue<in> qx,qy,qd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  qx.push(mxd/2);
  qy.push(mxd/2);
  qd.push(0);
  fld.resize(mxd,VI(mxd));
  avt.resize(mxd,VVI(mxd,VI(8)));
  in dst;
  forn(zz,n){
    cin>>dst;
    forn(i,mxd){
      forn(j,mxd){
	forn(c,8)
	  avt[i][j][c]=0;
      }
    }
    while(!qx.empty()){
      avt[qx.front()][qy.front()][qd.front()]=1;
      qx.pop();
      qy.pop();
      qd.pop();
    }
    forn(i,mxd){
      forn(j,mxd){
	forn(c,8){
	  if(!avt[i][j][c])
	    continue;
	  for(in z=1;z<=dst;++z){
	    fld[i+d[c][0]*z][j+d[c][1]*z]=1;
	  }
	  qx.push(i+d[c][0]*dst);
	  qy.push(j+d[c][1]*dst);
	  qd.push((c+1)%8);
	  qx.push(i+d[c][0]*dst);
	  qy.push(j+d[c][1]*dst);
	  qd.push((c+7)%8);
	}
      }
    }
  }
  in sm=0;
  forn(i,mxd){
    forn(j,mxd){
      sm+=fld[i][j];
    }
  }
  cout<<sm<<endl;
  return 0;
}