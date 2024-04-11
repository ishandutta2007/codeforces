// author: xay5421
// created: Mon Sep  6 13:46:48 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=505,dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int n,m,ans[N][N];
char s[N][N];
int zip(int k1,int k2){return (k1-1)*m+k2;}
struct ufs{
	int fa[N*N],dis[N*N];
	ufs(){rep(i,0,N*N-1)fa[i]=i,dis[i]=0;}
	int fd(int k1){
		if(fa[k1]!=k1){
			int k2=fa[k1];
			fa[k1]=fd(k2);
			dis[k1]^=dis[k2];
		}
		return fa[k1];
	}
	void mer(int k1,int k2,int k3){
		D("mer %d %d\n",k1,k2);
		int k1_=fd(k1),k2_=fd(k2);
		if(k1_==k2_){
			if((dis[k1]^dis[k2])!=k3){
				puts("NO"),exit(0);
			}
		}else{
			fa[k1_]=k2_;
			dis[k1_]=dis[k1]^dis[k2]^k3;
		}
	}
}o;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='X'){
		vector<int>v;
		rep(k,0,3){
			int ni=i+dx[k];
			int nj=j+dy[k];
			if(s[ni][nj]=='.')v.push_back(zip(ni,nj));
		}
		if(SZ(v)&1)puts("NO"),exit(0);
		if(SZ(v)==2){
			o.mer(v[0],v[1],1);
			ans[i][j]=5;
		}else if(SZ(v)==4){
			o.mer(v[0],v[1],1);
			o.mer(v[2],v[3],1);
			ans[i][j]=10;
		}
	}
	puts("YES");
	rep(i,1,n)rep(j,1,m){
		if(s[i][j]!='X'){
			o.fd(zip(i,j));
			ans[i][j]=o.dis[zip(i,j)]==0?1:4;
		}
		printf("%d%c",ans[i][j],j==m?'\n':' ');
	}
	return 0;
}