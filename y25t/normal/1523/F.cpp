#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 14
#define M 105

int n,m;

pii a[N],b[M];
int t[M];

int p[M];
inline bool cmp(int x,int y){
	return t[x]<t[y];
}

int da[1<<N][N],db[1<<N][M];
inline int dis(pii x,pii y){
	return std::abs(x.fir-y.fir)+std::abs(x.sec-y.sec);
}

int f[1<<N][M],g[1<<N][M];

int ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].fir,&a[i].sec);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&b[i].fir,&b[i].sec,&t[i]);
	for(int i=1;i<=m;i++)
		p[i]=i;
	std::sort(p+1,p+m+1,cmp);
	std::sort(t+1,t+m+1);
	memset(da,0x3f,sizeof(da));
	memset(db,0x3f,sizeof(db));
	for(int l=0;l<(1<<n);l++)
		for(int i=0;i<n;i++)
			if((l>>i)&1){
				for(int j=0;j<n;j++)
					da[l][j]=std::min(da[l][j],dis(a[i],a[j]));
				for(int j=1;j<=m;j++)
					db[l][j]=std::min(db[l][j],dis(a[i],b[p[j]]));
			}
	memset(f,0x3f,sizeof(f));
	memset(g,-1,sizeof(g));
	f[0][0]=0;
	for(int i=0;i<n;i++)
		f[1<<i][0]=0;
	for(int i=1;i<=m;i++)
		g[0][i]=1;
	for(int l=0;l<(1<<n);l++){
		for(int i=0;i<=m;i++){
			if(f[l][i]<inf){
				for(int j=0;j<n;j++)
					if(!((l>>j)&1))
						f[l|(1<<j)][i]=std::min(f[l|(1<<j)][i],f[l][i]+da[l][j]);
				for(int j=1;j<=m;j++)
					if(f[l][i]+db[l][j]<=t[j])
						g[l][j]=std::max(g[l][j],i+1);
			}
			if(g[l][i]>=0){
				for(int j=0;j<n;j++)
					if(!((l>>j)&1))
						f[l|(1<<j)][g[l][i]]=std::min(f[l|(1<<j)][g[l][i]],t[i]+std::min(dis(b[p[i]],a[j]),da[l][j]));
				for(int j=i+1;j<=m;j++)
					if(t[i]+std::min(dis(b[p[i]],b[p[j]]),db[l][j])<=t[j])
						g[l][j]=std::max(g[l][j],g[l][i]+1);
			}
		}
	}
	for(int l=0;l<(1<<n);l++)
		for(int i=1;i<=m;i++)
			ans=std::max(ans,g[l][i]);
	printf("%d\n",ans);
}