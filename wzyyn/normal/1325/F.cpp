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
const int N=100005;
vector<int> e[N];
int n,m,dep[N],fa[N];
int q[N],vis[N];
void dfs(int x){
	q[++*q]=x;
	dep[x]=dep[fa[x]]+1;
	for (auto i:e[x])
		if (!dep[i]){
			fa[i]=x;
			dfs(i);
		}
		else if (dep[i]<dep[x]){
			int l=dep[x]-dep[i]+1;
			if (l*l>=n){
				printf("2\n%d\n",l);
				for (int j=x;;j=fa[j]){
					printf("%d ",j);
					if (j==i) exit(0);
				}
			}
		}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	int l=1;
	for (;l*l<n;l++);
	int rem=l;
	printf("1\n");
	Rep(i,n,1){
		int x=q[i];
		if (vis[x]) continue;
		printf("%d ",x);
		if (!--rem) exit(0);
		For(j,0,l-2) vis[x]=1,x=fa[x];
	}
}