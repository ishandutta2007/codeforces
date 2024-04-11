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
const int N=25;
int ans_top,n,m,a[N][N];
vector<int> ans[100005];
pii p[N*N];
void SWP(int x,int y){
	//cout<<x<<' '<<y<<endl; 
	swap(p[x],p[y]);
	swap(a[p[x].fi][p[x].se],a[p[y].fi][p[y].se]);
}
void insert(vector<int> v){
	//cout<<233<<endl;
	ans[++ans_top]=v;
	Rep(i,v.size()-2,0) SWP(v[i],v.back());
}
void ROL(int x,int y){
	insert(vector<int>{a[x][y],a[x+1][y],a[x+1][y+1],a[x][y+1]});
}
void ROR(int x,int y){
	insert(vector<int>{a[x][y],a[x][y+1],a[x+1][y+1],a[x+1][y]});
}
void GOL(int x,int y){
	x==n?ROR(x-1,y-1):ROL(x,y-1);
}
void GOR(int x,int y){
	x==n?ROL(x-1,y):ROR(x,y);
}
void GOU(int x,int y){
	y==m?ROL(x-1,y-1):ROR(x-1,y);
}
void GOD(int x,int y){
	y==m?ROR(x,y-1):ROL(x,y);
}
void move(int v,int tx,int ty){
	//cout<<v<<' '<<tx<<' '<<ty<<' '<<p[v].fi<<' '<<p[v].se<<endl;
	for (;p[v].se<ty;GOR(p[v].fi,p[v].se));
	for (;p[v].se>ty;GOL(p[v].fi,p[v].se));
	for (;p[v].fi>tx;GOU(p[v].fi,p[v].se)); 
	for (;p[v].fi<tx;GOD(p[v].fi,p[v].se)); 
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m){
		scanf("%d",&a[i][j]);
		p[a[i][j]]=pii(i,j);
	}
	For(i,1,n-2){
		For(j,1,m-1) move(i*m-m+j,i,j);
		if (p[i*m]==pii(i,m)) continue;
		if (p[i*m].fi==i+1) GOD(p[i*m].fi,p[i*m].se);
		ROR(i,m-1); move(i*m,i+1,m); ROL(i,m-1);
	}
	For(j,1,m-2){
		move((n-2)*m+j,n-1,j);
		if (p[n*m-m+j]==pii(n,j)) continue;
		if (p[n*m-m+j].se==j+1) GOR(p[n*m-m+j].fi,p[n*m-m+j].se);
		ROL(n-1,j); move(n*m-m+j,n,j+1); ROR(n-1,j);
	}
	srand(time(NULL));
	for (;;){
		bool flg=0;
		For(i,1,n) For(j,1,m)
			if (a[i][j]!=i*m-m+j) flg=1;
		if (!flg) break;
		int tp=rand()%3;
		if (tp==0) ROL(n-1,m-1);
		if (tp==1) ROL(n-1,m-2);
		if (tp==2) insert(vector<int>{a[n-1][m-2],a[n-1][m-1],a[n-1][m],
									  a[n][m],a[n][m-1],a[n][m-2]});
	}
	printf("%d\n",ans_top);
	For(i,1,ans_top){
		printf("%d ",ans[i].size());
		for (auto j:ans[i]) printf("%d ",j);
		puts("");
	}
}
/*
5 5
10 22 13 9 17

*/