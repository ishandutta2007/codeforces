#include<bits/stdc++.h>
using namespace std;

const int N=605;
int n,m;
int e[N][N];
int vis[N];

long long d[N];
long long ve[N];
void solve(int id){
	memset(vis,0,sizeof(vis));
	memset(d,30,sizeof(d));
	
	d[id]=0;
	for (int i=0;i<n;i++){
		int p=-1;
		for (int j=0;j<n;j++)
			if (!vis[j]&&(p==-1||d[p]>d[j]))
				p=j;
		vis[p]=1;
		memset(ve,30,sizeof(ve));
		for (int j=0;j<n;j++)
			if (e[p][j]!=-1){
				int ny=(j+d[p])%n;
				ve[ny]=min(ve[ny],d[p]+e[p][j]);
				ve[0]=min(ve[0],n-ny+d[p]+e[p][j]);
			}
		for (int j=0;j<n;j++){
			ve[j+1]=min(ve[j+1],ve[j]+1);
			d[j]=min(d[j],ve[j]);
		}
	}
	for (int i=0;i<n;i++)
		printf("%lld ",d[i]);
	puts("");
}
int main(){
	scanf("%d%d",&n,&m);
	memset(e,-1,sizeof(e));
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x][y]=v;
	}
	for (int i=0;i<n;i++)
		solve(i);
}