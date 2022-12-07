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
const int N=2005;
int n,m1,m2;
struct SAT{
	bitset<N> e[N];
	int c[N],flg;
	void color(int x){
		if (c[x]!=-1) return;
		c[x]=1; c[x^1]=0;
		For(i,0,2*n-1)
			if (e[x][i]) color(i);
	}
	void init(int m){
		For(i,1,m){
			int x,y;
			scanf("%d%d",&x,&y);
			x=(x>0?x*2-2:-x*2-1);
			y=(y>0?y*2-2:-y*2-1);
			e[x][y^1]=e[y][x^1]=1;
		}
		For(i,0,2*n-1) e[i][i]=1;
		For(k,0,2*n-1) For(i,0,2*n-1)
			if (e[i][k]) e[i]|=e[k];
		For(i,0,2*n-1) if (e[i][i^1]&&e[i^1][i]) flg=1;
		if (!flg){
			For(i,0,2*n-1) c[i]=-1;
			For(i,0,2*n-1) if (e[i][i^1]) color(i^1);
		}
	}
	void solve(int c1=-1,int c2=-1){
		//cout<<c1<<' '<<c2<<endl;
		if (c1!=-1) color(c1);
		if (c2!=-1) color(c2);
		For(i,0,2*n-1) if (c[i]==-1) color(i);
		//cout<<c[0]<<endl;
		For(i,0,n-1) printf("%c ",'1'^(c[i*2]));
		exit(0);
	}
}f,g;
void check(SAT &f,SAT &g){
	if (f.flg) return;
	if (g.flg) return f.solve();
	For(i,0,2*n-1)
		if (f.c[i]&&!g.c[i]) 
			return f.solve(i);
	For(i,0,2*n-1) if (f.c[i]==-1)
		For(j,i,2*n-1) if (f.c[j]==-1)
			if (!f.e[i][j]&&g.e[i][j])
				return f.solve(i,j^1);
}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	f.init(m1); g.init(m2);
	check(f,g);
	check(g,f);
	puts("SIMILAR");
}