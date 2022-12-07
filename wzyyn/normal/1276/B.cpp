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
const int N=1000005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,m,a,b;
int q[N],vis[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int BFS(int S,int B){
	int ans=n-1;
	For(i,1,n) vis[i]=(i==B);
	int h=0,t=1; q[1]=S; vis[S]=1;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (!vis[e[i].to]){
				vis[e[i].to]=1;
				q[++t]=e[i].to;
			}
	}
	return n-1-t;
}
void solve(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	For(i,1,n) head[i]=0;
	tot=0;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	int ans1=BFS(b,a);
	int ans2=BFS(a,b);
	printf("%lld\n",1ll*ans1*ans2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}