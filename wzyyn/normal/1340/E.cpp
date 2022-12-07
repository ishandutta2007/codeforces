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
const int N=5005;
vector<int> e[N];
int n,m,dis[N][N],q[N];

int init(int p1,int p2,int p3){
	printf("%d %d %d\n",p1,p2,p3);
	fflush(stdout);
	int n;
	scanf("%d",&n);
	if (n==p1||n==p2||n==p3) exit(0);
	return n;
}
void SSSP(int S){
	For(i,1,n) dis[S][i]=-1;
	int t=1; q[1]=S; dis[S][S]=0;
	For(h,1,t) for (auto i:e[q[h]])
		if (dis[S][i]==-1) dis[S][i]=dis[S][q[h]]+1,q[++t]=i;
}
int walk(int x,int y){
	for (auto i:e[x]) if (dis[i][y]+1==dis[x][y]) return i;
	return x;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) SSSP(i);
	srand(time(NULL));
	int p1=rand()%n+1;
	int p2=rand()%n+1;
	int p3=rand()%n+1;
	for (;;){
		int p=init(p1,p2,p3),q[4]; q[0]=0;
		for (auto j:e[p]) q[++*q]=j;
		int to1,to2,to3,d=1<<30;
		for (auto i:e[p1]) if (i==p) return printf("%d %d %d\n",p,p2,p3),0;
		for (auto i:e[p2]) if (i==p) return printf("%d %d %d\n",p1,p,p3),0;
		for (auto i:e[p3]) if (i==p) return printf("%d %d %d\n",p1,p2,p),0;
		For(id1,1,*q) For(id2,1,*q) For(id3,1,*q){
			int v=dis[p1][q[id1]]+dis[p2][q[id2]]+dis[p3][q[id3]];
			v-=n+(id2!=id1?n:0)+(id3!=id2&&id3!=id1?n:0);
			if (v<d) d=v,to1=q[id1],to2=q[id2],to3=q[id3]; 
		}
		p1=walk(p1,to1);
		p2=walk(p2,to2);
		p3=walk(p3,to3);
	}
}