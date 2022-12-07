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
const int N=100005;
struct edge{
	int to,next;
}e[N*5];
int head[N],tot=1;
int n,m,top,deg[N],wzp[N];
int X[N*5],Y[N*5],vis[N*5];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void ADD(int x,int y){
	add(y,x); add(x,y);
	deg[x]^=1; deg[y]^=1;
}
void dfs(int x){
	for (;head[x];){
		int i=head[x];
		head[x]=e[i].next;
		if (!vis[i]){
			vis[i]=vis[i^1]=1;
			dfs(e[i].to);
			++top;
			X[top]=x; Y[top]=e[i].to;
			if (top&1) swap(X[top],Y[top]);
			//dfs(e[i].to);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		ADD(x,y);
	}
	int la=-1;
	For(i,1,n)
		if (deg[i]&1)
			if (la==-1) la=i;
			else ADD(la,i),++m,la=-1;
	assert(la==-1);
	if (m&1) ADD(1,1),++m;
	dfs(1);
	assert(top==m);
	printf("%d\n",top);
	For(i,1,top)
		printf("%d %d\n",X[i],Y[i]);
}
/*
1
3 6
1 1
2 2
3 2
2 1
1 3
1 1
*/