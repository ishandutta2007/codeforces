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
const int N=3005;
int q[N];
int fa[N],dep[N];
int n,co[N],dis[N];
vector<int> e[N];
double ans;
void dfs(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			if (!dep[i]){
				fa[i]=x;
				dep[i]=dep[x]+1;
				dfs(i);
			}
			else if (dep[i]<dep[x]){
				for (int y=x;;y=fa[y]){
					q[++*q]=y;
					if (y==i) break;
				}
			}
		}
}
void find(int x){
	for (auto i:e[x])
		if (!co[i]){
			co[i]=co[x];
			dep[i]=dep[x]+1;
			find(i);
		}
}
void SSSP(int x){
	For(i,1,n) dis[i]=-1;
	int h=0,t=1;
	q[1]=x; dis[x]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (dis[i]==-1&&co[i]==co[x]){
				dis[i]=dis[x]+1;
				q[++t]=i;
			}
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		e[++x].PB(++y);
		e[y].PB(x);
	}
	dfs(1);
	For(i,1,*q) co[q[i]]=i,dep[q[i]]=0;
	For(i,1,*q) find(q[i]);
	For(i,1,n){
		SSSP(i);
		For(j,i+1,n)
			if (co[i]==co[j])
				ans+=2.0/(dis[j]+1);
			else{
				int d1=dep[i]+dep[j];
				int d2=(co[i]+(*q)-co[j])%(*q);
				int d3=*q-d2;
				ans+=2.0/(d1+d2+1);
				ans+=2.0/(d1+d3+1);
				ans-=2.0/(d1+(*q));
			}
	}
	printf("%.10lf\n",ans+n);
}
/*
1-2 1-3 2-3 1-4 2-5
2-4 2-5 1-5 3-5
4-5
*/