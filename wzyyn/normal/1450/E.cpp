#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;

const int N=205;
int n,m,fa[N],v[N],fav[N];
struct node{
	int x,y,c;
};
vector<node> info;
int get(int x){
	if (x==fa[x]) return x;
	int p=get(fa[x]);
	v[x]=v[fa[x]]^fav[x];
	return p;
}
int q[N*N],vis[N],dis[N],inq[N];
vector<pii> e[N];
void SSSP(){
	For(i,1,n) vis[i]=0,dis[i]=1<<30;
	int h=0,t=0;
	For(i,1,n) vis[i]=1,q[++t]=i,dis[i]=0;
	q[1]=1; dis[1]=0;
	while (h!=t){
		int x=q[++h];
		if ((++inq[x])>n){
			puts("NO");
			exit(0);
		}
		vis[x]=0;
		for (auto i:e[x])
			if (dis[i.fi]>dis[x]+i.se){
				dis[i.fi]=dis[x]+i.se;
				if (!vis[i.fi]){
					vis[i.fi]=1;
					q[++t]=i.fi;
				}
			}
	}
}
void add(int x,int y,int v){
	e[x].PB(pii(y,v));
}
int f[N][N];
int main(){
	scanf("%d%d",&n,&m); 
	For(i,1,n) fa[i]=i;
	For(i,1,m){
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		info.PB((node){x,y,val});
		int px=get(x),py=get(y);
		if (px==py){
			if (v[x]^v[y]^1)
				return puts("NO"),0;
		}
		else{
			fa[px]=py;
			fav[px]=v[x]^v[y]^1;
		}
	}
	For(i,1,n) get(i);
	for (auto i:info)
		if (i.c==1){
			add(i.x,i.y,v[i.x]);
			add(i.y,i.x,-v[i.x]); 
		}
		else{
			if (v[i.x]) swap(i.x,i.y);
			add(i.x,i.y,0);
			add(i.y,i.x,1);
		}
	SSSP();
	puts("YES");
	memset(f,30,sizeof(f));
	For(i,1,n) f[i][i]=0;
	for (auto i:info)
		if (i.c==1){
			f[i.x][i.y]=min(f[i.x][i.y],1);
			f[i.y][i.x]=min(f[i.y][i.x],-1);
		}
		else{
			f[i.x][i.y]=min(f[i.x][i.y],1);
			f[i.y][i.x]=min(f[i.y][i.x],1);
		}
	For(k,1,n) For(i,1,n) For(j,1,n)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int ii=0,jj=0,p=-1;
	For(i,1,n) For(j,1,n)
		if (f[i][j]>p) ii=i,jj=j,p=f[i][j];
	cout<<p<<endl;
	For(i,1,n)
		printf("%d ",500000+f[ii][i]); 
}