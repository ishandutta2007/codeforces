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
const int N=2505;
int n,m,nd,S[N];
int dep[N],fa[N*2];
vector<int> e[N],E[N*2];
int f[N][N][3];
int tmp[N][3],sz[N];
void UPD(int &x,int y){
	x<y?x=y:233;
}
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for (auto i:e[x])
		if (!dep[i]){
			fa[i]=x; dfs(i);
			S[x]+=S[i];
			if (!S[i]){
				//cout<<"E1 "<<x<<' '<<i<<endl;
				E[x].PB(i);
				E[i].PB(x);
			}
		}
		else if (dep[i]<dep[x]&&i!=fa[x]){
			++nd; ++S[x]; --S[i];
			for (int y=x;;y=fa[y]){
				E[nd].PB(y);
				E[y].PB(nd);
				if (y==i) break;
			}
		}
}
void merge0(int x,int y){
	//cout<<"M1 "<<x<<' '<<y<<endl;
	memset(tmp,233,sizeof(tmp));
	For(i,0,sz[x]) For(j,0,sz[y])
		For(c1,0,2) For(c2,0,2)
			if ((c1!=0||c2!=2)&&(c1!=2||c2!=0))
				UPD(tmp[i+j][c2],f[x][i][c1]+f[y][j][c2]);
	sz[x]+=sz[y];
	For(i,0,sz[x]) For(c1,0,2) f[x][i][c1]=tmp[i][c1];
}
void merge1(int x,int y){
	//cout<<"M1 "<<x<<' '<<y<<endl;
	memset(tmp,233,sizeof(tmp));
	For(i,0,sz[x]) For(j,0,sz[y])
		For(c1,0,2) For(c2,0,2)
			if ((c1!=0||c2!=2)&&(c1!=2||c2!=0))
				UPD(tmp[i+j][c1],f[x][i][c1]+f[y][j][c2]);
	sz[x]+=sz[y];
	For(i,0,sz[x]) For(c1,0,2) f[x][i][c1]=tmp[i][c1];
}
void merge2(int x,int y){
	//cout<<x<<' '<<y<<endl;
	memset(f[n+2],233,sizeof(f[n+2]));
	For(c1,0,2){
		sz[n+1]=sz[x];
		memset(f[n+1],233,sizeof(f[n+1]));
		For(j,0,sz[x]) f[n+1][j][c1]=f[x][j][c1];
		for (auto j:E[y]) if (j!=x) merge0(n+1,j);
		For(c2,0,2) if ((c1!=0||c2!=2)&&(c1!=2||c2!=0))
			For(j,0,sz[n+1]) UPD(f[n+2][j][c1],f[n+1][j][c2]);
	}
	sz[x]=sz[n+1];
	memcpy(f[x],f[n+2],sizeof(f[x]));
}
void DP(int x){
	for (auto i:E[x])
		if (i!=fa[x]){
			fa[i]=x;
			DP(i);
		}
	if (x<=n){
		sz[x]=1;
		f[x][0][0]=1;
		f[x][0][1]=0;
		f[x][1][2]=0;
		for (auto i:E[x])
			if (i!=fa[x])
				if (i<=n) merge1(x,i);
				else merge2(x,i);
		//cout<<x<<' '<<f[x][0][0]<<endl;
	}
}
/*
0:
1:
2:

:DP
:

DP 
*/
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	nd=n;
	dfs(1);
	memset(fa,0,sizeof(fa));
	memset(f,233,sizeof(f));
	DP(1);
	For(i,0,n){
		int v=0;
		For(j,0,2) UPD(v,f[1][i][j]);
		printf("%d ",v);
	}
}
/*
4 4
1 2
2 3
3 4
4 1
*/