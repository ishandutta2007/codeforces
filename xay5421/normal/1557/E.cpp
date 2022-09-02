// author: xay5421
// created: Mon Aug  9 22:45:47 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T,cnt,nx,ny,dx,dy;
char opt[105];
bool can[10][10],ncan[10][10];
void ps(int x,int y){
	printf("%d %d\n",x,y);
	fflush(stdout);
	scanf("%s",opt);
	if(!strcmp(opt,"Done"))throw 0;
	++cnt;
	if(!strcmp(opt,"Right")){
		dx=0,dy=1;
	}else if(!strcmp(opt,"Left")){
		dx=0,dy=-1;
	}else if(!strcmp(opt,"Up")){
		dx=-1,dy=0;
	}else if(!strcmp(opt,"Down")){
		dx=1,dy=0;
	}else if(!strcmp(opt,"Down-Right")){
		dx=1,dy=1;
	}else if(!strcmp(opt,"Down-Left")){
		dx=1,dy=-1;
	}else if(!strcmp(opt,"Up-Left")){
		dx=-1,dy=-1;
	}else if(!strcmp(opt,"Up-Right")){
		dx=-1,dy=1;
	}else assert(0);
	auto chk=[&](int x,int y){
		return 1<=x&&x<=8&&1<=y&&y<=8;
	};
	memset(ncan,0,sizeof(ncan));
	rep(i,1,8)rep(j,1,8)if(can[i][j]){
		if(chk(i+dx,j+dy)){
			ncan[i+dx][j+dy]=1;
		}
	}
	rep(i,1,8)rep(j,1,8)if(i==x||j==y||i+j==x+y||i-j==x-y)ncan[i][j]=0;
	memcpy(can,ncan,sizeof(can));
	nx=x,ny=y;
}
void work(int i){
	int now=i;
	if(nx<i-1){
		ps(i-1,ny);
		while(nx<8&&dx==1)ps(nx+1,ny);
		if(nx>=8||ny>=8)return;
	}
	while(1){
		if(nx>=8||ny>=8)return;
		ps(nx,ny+1);
		while(nx<8&&dx==1)ps(nx+1,ny);
	}
}
void sol(){
	cnt=0;
	rep(i,1,8)rep(j,1,8)can[i][j]=1;
	nx=1,ny=1;
	ps(1,1);
	while(1){
		if(nx>1)ps(1,ny);
		if(ny>1)ps(1,1);
		rep(i,1,8){
			bool ok=0;
			rep(j,1,8)if(can[i][j])ok=1;
			if(ok){
				work(i);
				break;
			}
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		try{
			sol();
		}catch(int x){
			
		}
	}
	return 0;
}