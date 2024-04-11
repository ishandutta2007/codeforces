#include<bits/stdc++.h>
#define N 4005
#define P 998244353

inline int fmo(int x){
	return x+((x>>31)&P);
}

int n,m;
char s[N][N];

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
int a[N],sz[N],e[N];
inline void mrg(int u,int v){
	u=fnd(u),v=fnd(v);
	if(u!=v)
		f[v]=u,a[u]^=a[v],sz[u]+=sz[v],e[u]+=e[v];
	e[u]++;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	if(!(n&1)&&!(m&1)){
		int ans=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='?')
			ans=fmo(ans+ans-P);
		printf("%d\n",ans);
	}
	else if(!(n&1)||!(m&1)){
		if(!(m&1)){
			for(int i=1;i<=std::max(n,m);i++) for(int j=1;j<i;j++)
				std::swap(s[i][j],s[j][i]);
			std::swap(n,m);
		}
		int ans=0;
		for(int o=0;o<2;o++){
			int res=1;
			for(int i=1;i<=n;i++){
				int cnt=0,flg=0;
				for(int j=1;j<=m;j++)
					if(s[i][j]=='?'){
						if(!flg)
							flg=1;
						else
							res=fmo(res+res-P);
					}
					else
						cnt^=s[i][j]-'0';
				if(cnt!=o&&!flg)
					res=0;
			}
			ans=fmo(ans+res-P);
		}
		printf("%d\n",ans);
	}
	else{
		for(int i=1;i<=n+m;i++)
			sz[i]=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
			if(s[i][j]=='?')
				mrg(i,n+j);
			else
				a[fnd(i)]^=s[i][j]-'0',a[fnd(n+j)]^=s[i][j]-'0';
		int ans=0;
		for(int o=0;o<2;o++){
			int res=1;
			for(int i=1;i<=n+m;i++) if(!f[i]){
				if((!(sz[i]&1)&&a[i])||((sz[i]&1)&&a[i]!=o))
					res=0;
				else
					for(int j=0;j<e[i]-sz[i]+1;j++)
						res=fmo(res+res-P);
			}
			ans=fmo(ans+res-P);
		}
		printf("%d\n",ans);
	}
}