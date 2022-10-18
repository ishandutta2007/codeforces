#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define ll long long 
#define inf 0x3f3f3f3f3f3f3f3f
#define N 605

int n,m;

ll e[N][N],d[N][N];

inline void floyd(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=e[i][j]?e[i][j]:inf;
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
}

int q;
std::vector<pii> qry[N];

ll md[N];

bool f[N][N];

int ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u][v]=e[v][u]=w;
	}
	floyd();
	scanf("%d",&q);
	while(q--){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		qry[u].push_back(mp(v,l));
	}
	for(int u=1;u<=n;u++){
		for(int y=1;y<=n;y++)
			md[y]=-inf;
		for(auto i:qry[u]){
			int v=i.fir,l=i.sec;
			for(int y=1;y<=n;y++)
				md[y]=std::max(md[y],l-d[y][v]);
		}
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
				if(e[x][y]){
					if(d[u][x]+e[x][y]<=md[y])
						f[x][y]=f[y][x]=1;
				}
	}
	for(int u=1;u<=n;u++)
		for(int v=1;v<u;v++)
			if(f[u][v])
				ans++;
	printf("%d\n",ans);
}