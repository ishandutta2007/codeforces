#include<bits/stdc++.h>
#define N 222222
#define K 33
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
//head
using namespace std;
typedef long long LL;
int n,fa[K][N],lg[N],go[N],cost[N],x[N],h[N];
int g[N][K],dis[N][K];
int cmp(int i,int j){return x[i]+h[i]>x[j]+h[j]?i:j;}
int ask(int l,int r){int h=lg[r-l+1];return cmp(fa[h][l],fa[h][r-(1<<h)+1]);}
int main(){
	read(n);rep(i,1,n)read(x[i],h[i]);
	rep(i,2,n)lg[i]=lg[i-1]+(i==(i&-i));
	rep(i,1,n)fa[0][i]=i;
	rep(i,1,lg[n])for(int j=1;j+(1<<i)-1<=n;++j)fa[i][j]=cmp(fa[i-1][j],fa[i-1][j+(1<<(i-1))]);
	rep(i,0,20)g[n+1][i]=n+1;
	dep(i,n,1){
		int r=upper_bound(x+1,x+n+1,x[i]+h[i])-x;
		if(r==n+1)go[i]=n+1;
		else{
			int id=ask(i,r-1);
			if(id==i)go[i]=r,cost[i]=x[r]-x[i]-h[i];
			else go[i]=go[id],cost[i]=cost[id];
		}
		g[i][0]=go[i],dis[i][0]=cost[i];
		rep(j,0,19)g[i][j+1]=g[g[i][j]][j],dis[i][j+1]=dis[i][j]+dis[g[i][j]][j];
	}
	int m;read(m);
	rep(i,1,m){
		int l,r;read(l,r);
		int now=l,ans=0;
		if(g[now][0]>r)puts("0");
		else{
			dep(j,20,0)if(g[now][j]<r)ans+=dis[now][j],now=g[now][j];
			printf("%d\n",ans+(g[now][0]==r?dis[now][0]:0));
		}
	}
	return 0;
}