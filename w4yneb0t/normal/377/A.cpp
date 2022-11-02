#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
char mz[509][509];
in n,m,k,s;
in d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
  cin>>n>>m>>k;
  forn(i,n){
    cin>>mz[i];
    forn(j,m)
      if(mz[i][j]=='.')
	mz[i][j]='X';
  }
  s=0;
  in sx,sy,nx,ny;
  forn(i,n)
    forn(j,m)
    if(mz[i][j]=='X'){
      sx=i;
      sy=j;
      s++;
    }
  s-=k;
  queue<in> qx,qy;
  qx.push(sx);
  qy.push(sy);
  while(s){

    sx=qx.front();
    qx.pop();
    sy=qy.front();
    qy.pop();
    if(mz[sx][sy]!='X')
      continue;
    s--;
    mz[sx][sy]='.';
    for(in i=0;i<4;i++){
      nx=sx+d[i][0];
      ny=sy+d[i][1];
      if(nx<0 || nx>=n || ny<0 || ny>=m)
	 continue;
	 if(mz[nx][ny]!='X')
	   continue;
	 qx.push(nx);
	 qy.push(ny);
    }
  }
    forn(i,n)
      cout<<mz[i]<<endl;
  return 0;
}