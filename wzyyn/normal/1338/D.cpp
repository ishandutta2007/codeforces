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

const int N=100005;
vector<int> e[N];
int n,ans,f[N][2],g[N][2];
void dfs1(int x,int fa){
	f[x][0]=0; f[x][1]=0;
	int d=e[x].size()-(fa!=0);
	for (auto i:e[x]) if (i!=fa){
		dfs1(i,x);
		f[x][0]=max(f[x][0],max(f[i][0],f[i][1])-1);
		f[x][1]=max(f[x][1],f[i][0]);
	}
	f[x][0]+=d;
	f[x][1]++;
}
void upd(pii &x,pii &y,pii z){
	if (z>x) swap(x,z);
	y=max(y,z);
}
void dfs2(int x,int fa){
	if (!fa) g[x][0]=0,g[x][1]=0;
	pii mx1(0,x),mx2(-1,-1),mx3(0,x),mx4(-1,-1);
	upd(mx1,mx2,pii(max(g[x][0],g[x][1])-1,-1));
	upd(mx3,mx4,pii(g[x][0],-1));
	for (auto i:e[x]) if (i!=fa){
		upd(mx1,mx2,pii(max(f[i][0],f[i][1])-1,i));
		upd(mx3,mx4,pii(f[i][0],i));
	}
	//cout<<x<<' '<<f[x][0]<<' '<<f[x][1]<<' '<<g[x][0]<<' '<<g[x][1]<<endl;
	int d=e[x].size()-1;
	ans=max(ans,max(mx1.fi+d+1,mx3.fi));
	for (auto i:e[x]) if (i!=fa){
		g[i][0]=(mx1.se==i?mx2.fi:mx1.fi)+d;
		g[i][1]=(mx3.se==i?mx4.fi:mx3.fi)+1;
		dfs2(i,x);
	}
}
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%d\n",ans);
}
/*
:
:

 
9
1 2
1 3
2 4
2 5
2 6
3 7
3 8
3 9
*/