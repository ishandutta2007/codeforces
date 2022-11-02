#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=(1e5)+10;
int n,m;
struct node { int to,id,x,y; };
vector<node> a[maxn];
int cur[2][2][2];
bool vis[maxn];
int res[maxn][2],ans[2];
void update(int &x,int y) {	x+=y; if (x>=mod) x-=mod; }
void solve(int u,int p) {
	int x,y;
	vis[u]=1;
	for (int I=0,v;I<a[u].size();I++) {
		v=a[u][I].to; x=a[u][I].x,y=a[u][I].y;
		if (a[u][I].id==p) continue;
		if (vis[v]) {
			int tmp[2]={0,0};
			for (int i=0;i<=1;i++) for (int j=0;j<=1;j++) for (int k=0;k<=1;k++)
				update(tmp[k^((j^x)||(i^y))],cur[i][j][k]);
			int now[2]={0,0};
			for (int i=0;i<=1;i++) for (int j=0;j<=1;j++) update(now[i^j],(ll)tmp[i]*ans[j]%mod);
			ans[0]=now[0],ans[1]=now[1];
		} else {
			int nxt[2][2][2]; memset(nxt,0,sizeof(nxt));
			for (int i=0;i<=1;i++) for (int j=0;j<=1;j++) for (int k=0;k<=1;k++)
			for (int l=0;l<=1;l++)
				update(nxt[i][l][k^res[v][l^1]^((j^x)||(l^y))],cur[i][j][k]);
			memcpy(cur,nxt,sizeof(nxt));
			solve(v,a[u][I].id);
		}
		return;
	}	
	int tmp[2]={0,0};
	for (int i=0;i<=1;i++) for (int j=0;j<=1;j++) for (int k=0;k<=1;k++)
		update(tmp[k],cur[i][j][k]);
	int now[2]={0,0};
	for (int i=0;i<=1;i++) for (int j=0;j<=1;j++)
		update(now[i^j],(ll)tmp[i]*ans[j]%mod);
	ans[0]=now[0],ans[1]=now[1];
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m);
	int k,b,c,x[3];
	for (int i=1;i<=n;i++) {
		read(k);
		for (int j=1;j<=k;j++) read(x[j]);
		if (k==1) res[abs(x[1])][x[1]<0]^=1;
		else {
			b=abs(x[1]),c=abs(x[2]);
			a[b].push_back((node){c,i,x[1]<0,x[2]<0});
			a[c].push_back((node){b,i,x[2]<0,x[1]<0});
		}
	}
	ans[0]=1;
	for (int i=1;i<=m;i++)
		if (!vis[i]&&(int)a[i].size()<=1) {
			memset(cur,0,sizeof(cur));
			cur[0][0][res[i][1]]=1;
			cur[1][1][res[i][0]]=1;
			solve(i,0);
		}
	for (int i=1;i<=m;i++)
		if (!vis[i]) {
			memset(cur,0,sizeof(cur));
			cur[0][0][res[i][1]]=1;
			cur[1][1][res[i][0]]=1;
			solve(i,0);
		}
	printf("%d\n",ans[1]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/