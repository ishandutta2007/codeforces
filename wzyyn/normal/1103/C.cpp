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
const int N=250005;
int n,m,k,q[N];
int vis[N],d[N],fa[N];
vector<int> e[N];
void dfs(int x){
	vis[x]=1;
	d[x]=d[fa[x]]+1;
	if (d[x]==(n+k-1)/k){
		printf("PATH\n%d\n",(n+k-1)/k);
		for (int i=x;i;i=fa[i])
			printf("%d ",i);
		exit(0);
	}
	bool fl=1;
	for (auto i:e[x])
		if (!vis[i])
			fa[i]=x,dfs(i),fl=0;
	if (fl) q[++*q]=x;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	puts("CYCLES");
	For(i,1,k){
		int x=q[i],y=0,z=0;
		for (auto j:e[x]) if (j!=fa[x]) y?z=j:y=j;
		//cout<<"INF "<<x<<' '<<y<<' '<<z<<' '<<d[x]<<' '<<d[y]<<' '<<d[z]<<endl;
		if ((d[x]-d[y]+1)%3==0) swap(y,z);
		if ((d[x]-d[y]+1)%3==0){
			if (d[y]<d[z]) swap(y,z);
			printf("%d\n",d[y]-d[z]+2);
			for (int j=y;d[j]>=d[z];j=fa[j]) printf("%d ",j);
			printf("%d\n",x);
		}
		else{
			printf("%d\n",d[x]-d[y]+1);
			for (int j=x;d[j]>=d[y];j=fa[j]) printf("%d ",j);
			puts("");
		}
	}
}