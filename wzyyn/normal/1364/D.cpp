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
const int N=300005;
vector<int> e[N];
int vis[N],col[N];
int fa[N],dep[N];
int n,m,k,p1,p2;
void dfs1(int x){
	vis[x]=1;
	col[x]=1;
	for (auto i:e[x])
		if (i!=fa[x])
			if (!vis[i]){
				fa[i]=x;
				dep[i]=dep[x]+1;
				dfs1(i);
				if (col[i]) col[x]=0;
			}
			else if (dep[i]<dep[x]){
				p1=x,p2=i;
				if (dep[x]-dep[i]+1<=k){
					printf("2 %d\n",dep[x]-dep[i]+1);
					for (int y=x;;y=fa[y]){
						cout<<y<<' ';
						if (y==i) break;
					}
					exit(0);
				}
			}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n)
		if (!vis[i])
			dfs1(i);
	if (p1){
		printf("1\n%d ",p1);
		For(i,2,(k+1)/2) printf("%d ",p1=fa[fa[p1]]);
	}
	else{
		printf("1\n");
		int rem=(k+1)/2;
		For(i,1,n) if (rem&&col[i])
			--rem,printf("%d ",i);
	}
}