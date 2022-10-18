#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define P 998244353
#define N 305

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n,r;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int f[N][N<<1];
inline void dfs(int u,int fa){
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs(v,u);
	}
	f[u][n]=f[u][r+n+1]=1;
	for(int _=hd[u];_;_=e[_].nxt){
		int v=e[_].v;
		if(v==fa)
			continue;
		std::vector<pii> fu,fv;
		for(int i=0;i<=n+n+1;i++)
			if(f[u][i]){
				fu.push_back(mp(i-n-1,f[u][i]));
				f[u][i]=0;
			}
		for(int i=0;i<=n+n+1;i++)
			if(f[v][i])
				fv.push_back(mp(i-n-1,f[v][i]));
		for(auto x:fu)
			for(auto y:fv){
				int i=x.fir,j=y.fir,k;
				if(i<0&&j<0)
					k=std::min(i,j-1);
				else if(i<0&&j>=0)
					k=i+j>=0?j-1:i;
				else if(i>=0&&j<0)
					k=i+j>=0?i:j-1;
				else
					k=std::max(i,j-1);
				k+=n+1;
				f[u][k]=fmo(f[u][k]+1ll*x.sec*y.sec%P-P);
			}
	}
}

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	for(r=1;r<n;r++){
		memset(f,0,sizeof(f));
		dfs(1,0);
		for(int i=0;i<=n;i++)
			ans=fmo(ans+f[1][i]-P);
	}
	ans=1ll*ans*fp(fp(2),n)%P;
	printf("%d\n",ans);
}