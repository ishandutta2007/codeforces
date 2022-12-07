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
const int N=260;
vector<int> vec[10];
vector<int> e[N];
int CT[N],q[N],vis[N],a[N],b[N];
int qq[10],spe[10],out[10],n;
void work(){
	//puts("AHA");
	memset(vis,0,sizeof(vis));
	memset(out,0,sizeof(out));
	For(i,1,n) CT[i]=1;
	For(i,0,n) e[i].resize(0);
	For(i,1,3) CT[spe[i]]=0;
	int h=0,t=1; q[1]=vis[1]=1;
	while (h!=t){
		int x=q[++h];
		int v=(CT[x]?a[x]&b[x]:a[x]);
		if (!out[v]) out[v]=x;
		//printf("%d %d %d\n",x,v,a[x]);
		For(i,1,n) if (a[i])
			if (out[a[i]]&&!vis[i]&&CT[i]){
				e[i].push_back(out[a[i]]);
				vis[i]=1; q[++t]=i;
			}
		if (out[1]&&out[2]&&spe[1]&&!vis[spe[1]]){
			e[spe[1]].PB(out[1]);
			e[spe[1]].PB(out[2]);
			q[++t]=spe[1];
			vis[spe[1]]=1;
		}
		if (out[1]&&out[4]&&spe[2]&&!vis[spe[2]]){
			e[spe[2]].PB(out[1]);
			e[spe[2]].PB(out[4]);
			q[++t]=spe[2];
			vis[spe[2]]=1;
		}
		if (out[2]&&out[4]&&spe[3]&&!vis[spe[3]]){
			e[spe[3]].PB(out[2]);
			e[spe[3]].PB(out[4]);
			q[++t]=spe[3];
			vis[spe[3]]=1;
		}
	}
	For(i,1,n)
		if (a[i]&&!vis[i])
			return;
	puts("Possible");
	int sumi=0;
	For(i,1,n){
		sumi+=e[i].size();
		printf("%d ",CT[i]);
	}
	puts("");
	printf("%d\n",sumi);
	For(i,1,n)
		For(j,0,e[i].size()-1)
			printf("%d %d\n",e[i][j],i);
	exit(0);
}
void dfs(int x){
	if (x==4) return work();
	dfs(x+1);
	if (!vec[qq[x]].size()) return;
	spe[x]=vec[qq[x]].back();
	vec[qq[x]].pop_back();
	dfs(x+1);
	vec[qq[x]].push_back(spe[x]);
	spe[x]=0;
}
void read(int &x){
	int y;
	For(i,1,3) scanf("%d",&y),x=x*2+y;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) read(a[i]);
	For(i,1,n) read(b[i]),vec[a[i]].PB(i);
	qq[1]=3; qq[2]=5; qq[3]=6;
	dfs(1);
	puts("Impossible");
}
/*
3
1 1 1
1 0 1
1 1 1
1 1 1
0 0 0
1 0 1
*/