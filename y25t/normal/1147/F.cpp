#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define N 55

int T;

int n,a[N<<1][N<<1];

int val[N<<1];
inline bool cmp(int x,int y){
	return val[x]<val[y];
}

int b[N][N],nxt[N<<1];
bool flg[N<<1];
std::queue<int> q;
inline void sol(){
	memset(flg,0,sizeof(flg));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=j+n;
			val[j+n]=a[i][j+n];
		}
		std::sort(b[i]+1,b[i]+n+1,cmp);
	}
	for(int i=1;i<=n;i++)
		q.push(i);
	while(q.size()){
		int u=q.front();
		q.pop();
		if(flg[u])
			continue;
		for(int i=1;i<=n;i++){
			int v=b[u][i];
			if(!flg[v]||a[v][u]>a[v][nxt[v]]){
				if(flg[v]){
					flg[nxt[v]]=0;
					q.push(nxt[v]);
				}
				else
					flg[v]=1;
				nxt[u]=v;
				nxt[v]=u;
				flg[u]=1;
				break;
			}
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				int w;
				scanf("%d",&w);
				a[i][j+n]=a[j+n][i]=w;
			}
		puts("B");
		fflush(stdout);
		getchar();
		if(getchar()=='D')
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					a[i][j+n]*=-1;
					a[j+n][i]*=-1;
				}
		int x;
		scanf("%d",&x);
		if(x>n)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					a[i][j+n]*=-1;
					a[j+n][i]*=-1;
				}
		sol();
		while(1){
			printf("%d\n",nxt[x]);
			fflush(stdout);
			scanf("%d",&x);
			if(x<0)
				break;
		}
	}
}