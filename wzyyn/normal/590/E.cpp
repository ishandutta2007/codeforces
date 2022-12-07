#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int M=10000005;
const int N=755;
int ch[M][2],fail[M],q[M];
int n,m,nd,ans,lp[N],rp[N];
int mat[N],vis[N],at[M],id[N];
int e[N][N],vl[N],vr[N];
char s[M];
void build(){
	fail[1]=1;
	int h=0,t=0;
	For(i,0,1)
		if (ch[1][i]){
			q[++t]=ch[1][i];
			fail[ch[1][i]]=1;
		}
		else
			ch[1][i]=1;
	while (h!=t){
		int x=q[++h];
		For(i,0,1)
			if (ch[x][i]){
				fail[ch[x][i]]=ch[fail[x]][i];
				if (!at[ch[x][i]])
					at[ch[x][i]]=at[fail[ch[x][i]]];
				q[++t]=ch[x][i];
			}
			else
				ch[x][i]=ch[fail[x]][i];
	}
}
bool dfs(int x){
	For(i,1,n)
		if (x!=i&&e[x][i]&&!vis[i]){
			vis[i]=1;
			if (!mat[i]||dfs(mat[i])){
				mat[i]=x;
				return 1;
			}
		}
	return 0;
}
void dfs2(int x){
	For(i,1,n)
		if (x!=i&&e[x][i]&&!vr[i]){
			vr[i]=1,vl[mat[i]]=0;
			dfs2(mat[i]);
		}
}
int main(){
	scanf("%d",&n);
	nd=1;
	For(i,1,n){
		lp[i]=rp[i-1];
		scanf("%s",s+lp[i]);
		rp[i]=strlen(s+lp[i])+lp[i];
		int x=1;
		For(j,lp[i],rp[i]-1){
			int c=(s[j]-='a');
			if (!ch[x][c]) ch[x][c]=++nd;
			x=ch[x][c];
		}
		if (!at[x]){
			at[x]=++m;
			id[m]=i;
		}
	}
	build();
	For(i,1,m){
		int x=1;
		For(j,lp[id[i]],rp[id[i]]-1){
			x=ch[x][s[j]];
			if (j==rp[id[i]]-1) x=fail[x];
			e[at[x]][i]=1;
		}
		e[i][i]=1;
	}
	For(k,1,m) For(i,1,m) if (e[i][k])
		For(j,1,m) e[i][j]|=e[k][j];
	For(i,1,m){
		memset(vis,0,sizeof(vis));
		if (dfs(i)) ++ans;
	}
	For(i,1,m) vl[mat[i]]=1;
	For(i,1,m) if (!vl[i]) dfs2(i);
	printf("%d\n",m-ans);
	For(i,1,m)
		if (!vl[i]&&!vr[i])
			printf("%d ",id[i]);
}