#include<bits/stdc++.h>
#define ll long long
#define P 998244353
#define N 100005

inline int fmo(int x){
	return x+((x>>31)&P);
}

int T;

int n,a[N];

int F[N],*f=F,B[N],*b=B,G[N],*g=G,C[N],*c=C;
bool vis[N];
std::vector<int> u,v;

int ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=0;
		f[1]=0,b[1]=1;
		u.push_back(1);
		for(int i=n;i;i--){
			for(auto x:u){
				int tmp=fmo(f[x]+1ll*(x-1)*b[x]%P-P);
				ans=fmo(ans+tmp-P);
				int z=a[i]/x,y=(a[i-1]-1)/z+1;
				g[y]=fmo(g[y]+tmp-P);
				c[y]=fmo(c[y]+b[x]-P);
				if(!vis[y])
					vis[y]=1,v.push_back(y);
				f[x]=b[x]=0;
			}
			c[1]=fmo(c[1]+1-P);
			if(!vis[1])
				vis[1]=1,v.push_back(1);
			std::swap(f,g),std::swap(b,c),std::swap(u,v);
			for(auto x:u)
				vis[x]=0;
			v.clear();
		}
		u.clear(),v.clear();
		printf("%d\n",ans);
	}
}