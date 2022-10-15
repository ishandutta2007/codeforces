#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;

const int maxn = 5007;
int n,K,V;
bool fg[maxn][maxn];
int v[maxn];
LL cnt[maxn],tot=0;

int main(){
	scanf("%d%d%d",&n,&K,&V);
	memset(fg,0,sizeof(fg));
	for (int i=1;i<=n;++i){
		scanf("%d",&v[i]);
		cnt[i]=v[i];
		tot+=v[i];
	}
	fg[0][0]=1;
	for (int i=0;i<n;++i){
		for (int j=0;j<K;++j){
			if(fg[i][j]){
				fg[i+1][j]=fg[i+1][(j+v[i+1])%K]=1;
			}
		}
	}
	if (tot<V||!fg[n][V%K]){
		printf("NO");
	} 
	else{
		printf("YES\n");
		bool vis[maxn];
		int u=V%K,xd=-1;
		memset(vis,0,sizeof(vis));
		for (int i=n;i>0;--i){
			if (!fg[i-1][u]){
				vis[i]=1;
				xd=i;
				u=((u-v[i])%K+K)%K;
			}
		}
		if (xd==-1){
			for (int i=2;i<=n;++i){
				printf("1000000000 %d 1\n",i);
			}
			if (V/K!=0){
				printf("%d 1 2\n",V/K);
			}
		}
		else{
			for (int i=1;i<=n;++i){
				if (i==xd||!vis[i]) continue;
				cnt[xd]+=cnt[i];
				cnt[i]=0;
				printf("1000000000 %d %d\n",i,xd);
			}
			for (int i=1;i<=n;++i){
				if (i==(xd%n)+1||vis[i]) continue;
				cnt[(xd%n)+1]+=cnt[i];
				cnt[i]=0;
				printf("1000000000 %d %d\n",i,(xd%n)+1);
			}
			if (cnt[xd]<V){
				printf("%lld %d %d\n",(V-cnt[xd])/K,(xd%n)+1,xd);
			}
			if (cnt[xd]>V){
				printf("%lld %d %d\n",(cnt[xd]-V)/K,xd,(xd%n)+1);
			}
		}
	}
	return 0;
}