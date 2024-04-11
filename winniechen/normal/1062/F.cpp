#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 300050
int head[N],to[N],nxt[N],cnt,n,m,xx[N],yy[N],du[N];
int tot[2][N],Q[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void Topsort(int opt) {
	int i,x;
	int l=0,r=0;
	for(i=1;i<=n;i++) if(!du[i]) {
		Q[r++]=i;
	}
	while(l<r) {
		x=Q[l++];
		if(r-l==0) tot[opt][x]=n-r;
		else if(r-l==1) {
			int flg=1,y=Q[l];
			for(i=head[y];i;i=nxt[i]) {
				if(du[to[i]]==1) {flg=0; break;}
			}
			if(flg) tot[opt][x]=n-r;
			else tot[opt][x]=-n;
		}else tot[opt][x]=-n;
		for(i=head[x];i;i=nxt[i]) {
			du[to[i]]--;
			if(!du[to[i]]) {
				Q[r++]=to[i];
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		xx[i]=x; yy[i]=y;
		add(x,y); du[y]++;
	}
	Topsort(0);
	memset(du,0,sizeof(du));
	memset(head,0,sizeof(head)); cnt=0;
	for(i=1;i<=m;i++) {
		add(yy[i],xx[i]); du[xx[i]]++;
	}
	Topsort(1);
	int ans=0;
	for(i=1;i<=n;i++) {
		if(tot[0][i]+tot[1][i]>=n-2) {
			ans++;
		}
	}
	printf("%d\n",ans);
}