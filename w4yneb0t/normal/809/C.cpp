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
const in mdl=1000000007;
in wys[2][2][2][2];
in sm[2][2][2][2];
in p2(in a){
  return 1LL<<a;
}
in a(in x, in y, in k){
  if(x<1 || y<1)
    return 0;
  forn(z,2){
    forn(i,2){
      forn(j,2){
	forn(f,2){
	  wys[z][i][j][f]=sm[z][i][j][f]=0;
	}
      }
    }
  }
  in sw=1;
  in nw=0;
  wys[nw][0][0][0]=1;
  in dx,dy,dk;
  in nk;
  in rx,ry,rk;
  for(in i=32;i>=0;--i){
    swap(sw,nw);
    forn(a,2){
      forn(b,2){
	forn(c,2){
	  wys[nw][a][b][c]=sm[nw][a][b][c]=0;
	  wys[sw][a][b][c]%=mdl;
	  sm[sw][a][b][c]%=mdl;
	}
      }
    }
    dx=!!(x&p2(i));
    dy=!!(y&p2(i));
    dk=!!(k&p2(i));
    forn(ox,2){
      forn(oy,2){
	forn(ok,2){
	  forn(nx,2){
	    if(ox==1)
	      rx=1;
	    else{
	      if(nx>dx)
		continue;
	      if(nx==dx)
		rx=0;
	      if(nx<dx)
		rx=1;
	    }
	    forn(ny,2){
	      if(oy==1)
		ry=1;
	      else{
		if(ny>dy)
		  continue;
		if(ny==dy)
		  ry=0;
		if(ny<dy)
		  ry=1;
	      }
	      nk=nx^ny;
	      if(ok==1)
		rk=1;
	      else{
		if(nk>dk)
		  continue;
		if(nk==dk)
		  rk=0;
		if(nk<dk)
		  rk=1;
	      }
	      wys[nw][rx][ry][rk]+=wys[sw][ox][oy][ok];
	      sm[nw][rx][ry][rk]+=sm[sw][ox][oy][ok]+nk*p2(i)*wys[sw][ox][oy][ok]%mdl;
	    }
	  }
	}
      }
    }
  }
  in rs=wys[nw][1][1][1]+sm[nw][1][1][1];
  rs%=mdl;
  return rs;
}
void doq(){
  in x1,x2,y1,y2,k;
  cin>>x1>>y1>>x2>>y2>>k;
  in sm=0;
  sm+=a(x2,y2,k);
  sm-=a(x1-1,y2,k);
  sm-=a(x2,y1-1,k);
  sm+=a(x1-1,y1-1,k);
  sm%=mdl;
  if(sm<0)
    sm+=mdl;
  cout<<sm<<"\n";
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in q;
  cin>>q;
  forn(z,q)
    doq();
  return 0;
}