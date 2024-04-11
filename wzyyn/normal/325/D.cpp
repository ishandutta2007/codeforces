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
int id[N][N*2],Vis[N][N*2],nd;
int fa[N*N*2],R,C,Q;
int vis[N*N*2],ans;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&R,&C,&Q);
	if (C==1) return puts("0"),0;
	For(i,1,R) For(j,1,2*C) id[i][j]=++nd;
	For(i,1,nd) fa[i]=i;
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		if (Vis[x][y]){
			++ans;
			continue;
		}
		For(dx,-1,1) For(dy,-1,1) if (dx||dy){
			int px=x+dx,py=y+dy;
			if (py<1) py+=2*C;
			if (py>2*C) py-=2*C;
			if (px<1||px>R||!Vis[px][py]) continue;
			vis[get(id[px][py])]=i;
		}
		bool fl=1;
		For(dx,-1,1) For(dy,-1,1) if (dx||dy){
			int px=x+dx,py=y+C+dy;
			if (py<1) py+=2*C;
			if (py>2*C) py-=2*C;
			if (px<1||px>R||!Vis[px][py]) continue;
			if (vis[get(id[px][py])]==i) fl=0;
		}
		if (!fl) continue;
		Vis[x][y]=Vis[x][y+C]=1;
		//puts("KO");
		++ans;
		For(dx,-1,1) For(dy,-1,1) if (dx||dy){
			int px=x+dx,py=y+dy;
			if (py<1) py+=2*C;
			if (py>2*C) py-=2*C;
			if (px<1||px>R||!Vis[px][py]) continue;
			fa[get(id[px][py])]=get(id[x][y]);
		}
		For(dx,-1,1) For(dy,-1,1) if (dx||dy){
			int px=x+dx,py=y+C+dy;
			if (py<1) py+=2*C;
			if (py>2*C) py-=2*C;
			if (px<1||px>R||!Vis[px][py]) continue;
			fa[get(id[px][py])]=get(id[x][y+C]);
		}
		assert(get(id[x][y])!=get(id[x][y+C]));
	}
	cout<<ans<<endl;
}
/*
3 4 11
2 2
3 2
2 3
3 4
3 1
1 3
2 1
1 1
1 4
1 2
3 3
*/