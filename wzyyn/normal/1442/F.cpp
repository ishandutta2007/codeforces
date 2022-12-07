#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1005;
int n,m,T;
int e[N][N],q[N],deg[N];
int id[N],adj[N];
void topo(){
	For(i,1,n) For(j,1,n)
		if (e[i][j]) ++deg[j];
	int h=0,t=0;
	For(i,1,n)
		if (!deg[i])
			q[++t]=i;
	while (h!=t){
		int x=q[++h];
		For(i,1,n)
			if (e[x][i])
				if (!--deg[i])
					q[++t]=i; 
	}
}
int q2[5005];
int vi[1<<20|5]; 
void build(){
	*q=0;
	vector<pii> opt;
	int p1=max(1,n-19),m=n-p1+1;
	q2[++*q2]=0;
	For(i,0,m-1) q2[++*q2]=1<<i;
	For(i,0,m-1) For(j,i+1,m-1) q2[++*q2]=(1<<i)|(1<<j);
	For(i,0,m-1) For(j,i+1,m-1) For(k,j+1,m-1) q2[++*q2]=(1<<i)|(1<<j)|(1<<k);
	For(i,p1,n) For(j,i+1,n)
		if (!e[q[i]][q[j]]) opt.PB(pii(q[i],q[j]));
	For(i,p1,n){
		id[q[i]]=adj[q[i]]=1<<(n-i);
		vi[id[q[i]]]=1;
	}
	For(i,1,p1-1){
		int x=q[i];
		opt.PB(pii(x,x));
		For(j,1,n) if (e[x][j]&&id[j]) adj[x]|=id[j];
		For(j,1,*q2) if (!vi[adj[x]^q2[j]]){
			adj[x]^=q2[j]; vi[adj[x]]=1;
			For(p,p1,n) if (q2[j]&id[q[p]]) opt.PB(pii(x,q[p]));
			break;
		}
	}
	printf("%d\n",opt.size());
	for (auto i:opt)
		if (e[i.fi][i.se])
			printf("- %d %d\n",i.fi,i.se);
		else printf("+ %d %d\n",i.fi,i.se);
	fflush(stdout);
}
void solve(){
	int p1=max(1,n-19),m=n-p1+1,vadj=0;
	For(i,p1,n){
		printf("? 1 %d\n",q[i]);
		fflush(stdout);
		char s[10];
		scanf("%s",s+1);
		if (s[1]=='L'){
			printf("! %d\n",q[i]);
			fflush(stdout);
			scanf("%s",s+1);
			return;
		}
		if (s[1]=='W') vadj|=id[q[i]];
	}
	For(i,1,n) if (adj[i]==vadj) printf("! %d\n",i);
	fflush(stdout);
	char s[10];
	scanf("%s",s+1);
}
int main(){
	scanf("%d%d%d",&n,&m,&T);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x][y]=1;
	}
	topo();
	build();
	while (T--) solve();
}