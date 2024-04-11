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
const int N=305;
const int C=2000005;
int n,m,Q,nd,mx,a[N][N];
int id[N][N],vis[N][N];
int fa[N*N],dif[C];
struct node{
	int T,x,y;
};
vector<node> vI[C];
vector<node> vE[C];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int merge(int x,int y){
	//cout<<'M'<<' '<<x<<' '<<y<<endl;
	x=get(x); y=get(y);
	if (x==y) return 0;
	//cout<<'M'<<' '<<x<<' '<<y<<endl;
	//cout<<'M'<<' '<<x<<' '<<y<<endl;
	fa[x]=y; return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) For(j,1,m) id[i][j]=++nd;
	For(i,1,n) For(j,1,m)
		vI[0].PB((node){0,i,j});
	For(i,1,Q){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if (a[x][y]==c) continue;
		vE[a[x][y]].PB((node){i-1,x,y});
		vI[a[x][y]=c].PB((node){i,x,y});
		mx=max(mx,c);
	}
	For(i,1,n) For(j,1,m)
		vE[a[i][j]].PB((node){Q,i,j});
	For(i,1,nd) fa[i]=i;
	For(i,0,mx){
		int sum=0;
		for (auto j:vI[i]){
			dif[j.T]-=sum;
			sum++; vis[j.x][j.y]=1; //cout<<sum<<' ';
			if (j.x!=1&&vis[j.x-1][j.y]) sum-=merge(id[j.x-1][j.y],id[j.x][j.y]);//cout<<sum<<' ';
			if (j.y!=1&&vis[j.x][j.y-1]) sum-=merge(id[j.x][j.y-1],id[j.x][j.y]);//cout<<sum<<' ';
			if (j.x!=n&&vis[j.x+1][j.y]) sum-=merge(id[j.x+1][j.y],id[j.x][j.y]);///cout<<sum<<' ';
			if (j.y!=m&&vis[j.x][j.y+1]) sum-=merge(id[j.x][j.y+1],id[j.x][j.y]);//cout<<sum<<' ';
			dif[j.T]+=sum; //cout<<endl;
		}
		for (auto j:vI[i]){
			fa[id[j.x][j.y]]=id[j.x][j.y];
			vis[j.x][j.y]=0;
		}
		reverse(vE[i].begin(),vE[i].end());
		sum=0;
		for (auto j:vE[i]){
			dif[j.T+1]+=sum;
			sum++; vis[j.x][j.y]=1;
			if (j.x!=1&&vis[j.x-1][j.y]) sum-=merge(id[j.x-1][j.y],id[j.x][j.y]);
			if (j.y!=1&&vis[j.x][j.y-1]) sum-=merge(id[j.x][j.y-1],id[j.x][j.y]);
			if (j.x!=n&&vis[j.x+1][j.y]) sum-=merge(id[j.x+1][j.y],id[j.x][j.y]);
			if (j.y!=m&&vis[j.x][j.y+1]) sum-=merge(id[j.x][j.y+1],id[j.x][j.y]);
			dif[j.T+1]-=sum;
		}
		for (auto j:vE[i]){
			fa[id[j.x][j.y]]=id[j.x][j.y];
			vis[j.x][j.y]=0;
		}
	}
	For(i,1,Q) dif[i]+=dif[i-1];
	For(i,1,Q) printf("%d\n",dif[i]); 
} 
/*
22
22
24
*/