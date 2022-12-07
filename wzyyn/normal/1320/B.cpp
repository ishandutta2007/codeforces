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
const int N=200005;
vector<int> e[N];
int n,m,K,mn,mx,qq[N],q[N],from[N],dis[N];
void bfs(int S){
	For(i,1,n) dis[i]=-1,from[i]=0;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (dis[i]==-1){
				dis[i]=dis[x]+1;
				from[i]++;
				q[++t]=i;
			}
			else if (dis[i]==dis[x]+1)
				++from[i];
	}
	//cout<<from[2]<<' '<<dis[2]<<' '<<dis[3]<<endl;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		 e[y].PB(x);
	}
	scanf("%d",&K);
	For(i,1,K) scanf("%d",&qq[i]);
	bfs(qq[K]);
	For(i,2,K)
		if (dis[qq[i-1]]!=dis[qq[i]]+1)
			mn++,mx++;
		else if (from[qq[i-1]]!=1)
			mx++;
	printf("%d %d\n",mn,mx);
}