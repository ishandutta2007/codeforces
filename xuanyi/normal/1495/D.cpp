// author: xay5421
// created: Wed Mar 10 20:49:20 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=405,M=605;
int n,m,dep[N],cnt[N],ans[N][N],q[N],dis[N][N],deg[N];
bool pd[N];
int pp,lnk[N],nxt[M*2],to[M*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int calc(int i){
	rep(k,1,n)dep[k]=-1;
	dep[i]=0;
	int he=0,ta=0;
	q[++ta]=i;
	cnt[i]=1;
	while(he!=ta){
		int k1=q[++he];
		for(int k=lnk[k1];k;k=nxt[k]){
			if(dep[to[k]]==-1)dep[to[k]]=dep[k1]+1,cnt[to[k]]=0,q[++ta]=to[k];
			if(dep[to[k]]==dep[k1]+1)++cnt[to[k]];
		}
	}
	int res=1;
	rep(i,1,n)res=mu(res,cnt[i]);
	return res;
}
int get(int i){
	if(!pd[i])return i;
	int tem=-1,w=1e9;
	rep(k,1,n)if(!pd[k]&&dis[i][k]<w)tem=k,w=dis[i][k];
	assert(tem!=-1);
	return tem;
}
int main(){
	rd(n),rd(m);
	if(m==n-1){
		rep(i,1,n){
			rep(j,1,n)printf("%d ",1);
			puts("");
		}
		return 0;
	}
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		ae(k1,k2),ae(k2,k1);
		++deg[k1],++deg[k2];
	}
	{
		int he=0,ta=0;
		rep(i,1,n){
			if(deg[i]==1)q[++ta]=i,pd[i]=1;
		}
		while(he!=ta){
			int k1=q[++he];
			for(int i=lnk[k1];i;i=nxt[i])if(--deg[to[i]]==1){
				q[++ta]=to[i];
				pd[to[i]]=1;
			}
		}
	}
	rep(i,1,n){
		int he=0,ta=0;
		rep(j,1,n)dis[i][j]=-1;
		dis[i][i]=0;
		q[++ta]=i;
		while(he!=ta){
			int k1=q[++he];
			for(int k=lnk[k1];k;k=nxt[k])if(dis[i][to[k]]==-1){
				dis[i][to[k]]=dis[i][k1]+1;
				q[++ta]=to[k];
			}
		}
	}
	rep(i,1,n){
		ans[i][i]=calc(i);
	}
	rep(a,1,n){
		rep(b,1,n){
			int i=get(a),j=get(b);
			if(i==j){printf("%d ",ans[i][i]);continue;}
			bool ok=1;
			vector<int>cnt(dis[i][j]+1);
			rep(k,1,n)if(dis[i][k]+dis[k][j]==dis[i][j])++cnt[dis[i][k]];
			rep(k,0,dis[i][j])if(cnt[k]!=1)ok=0;
			if(!ok){printf("%d ",0);continue;}
			int res=1;
			rep(k,1,n)if(dis[i][k]+dis[j][k]!=dis[i][j]){
				int tt=0;
				for(int t=lnk[k];t;t=nxt[t])if(dis[to[t]][i]-dis[to[t]][j]==dis[k][i]-dis[k][j]&&dis[to[t]][i]+1==dis[k][i])++tt;
				res=mu(res,tt);
			}
			printf("%d ",res);
		}
		puts("");
	}
	return 0;
}