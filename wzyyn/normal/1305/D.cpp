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
const int N=1005;
int val[N],dS[N],dT[N],q[N],n;
vector<int> e[N];
int bfs(int S,int *d){
	For(i,1,n) d[i]=-1;
	int h=0,t=1,id=S;
	q[1]=S; d[S]=val[S];
	while (h!=t){
		int x=q[++h];
		if (d[x]>d[id]) id=x;
		for (auto i:e[x]) if (d[i]==-1)
			d[i]=d[x]+val[i],q[++t]=i;
	}
	return id;
}
void color(int x,int fa){
	for (auto i:e[x])
		if (i!=fa){
			val[i]&=val[x];
			color(i,x);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) val[i]=1;
	for (;;){
		int x=bfs(1,dS),y=bfs(x,dS),z; bfs(y,dT);
		if (dS[y]==1) return printf("! %d\n",x),0;
		printf("? %d %d\n",x,y);
		fflush(stdout);
		scanf("%d",&z);
		For(i,1,n) if (i!=z&&dS[i]+dT[i]-val[i]==dS[y]) val[i]=0;
		color(z,0);
	}
}