#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=200005;

struct node{
	int x,y; ll d;
	bool operator <(const node &a)const{
		return d>a.d;
	}
};
priority_queue<node> Q;
int n,m;
ll dis[N][5];
int vis[N][5];
vector<pii> e[N];

void UPD(int x,int y,ll d){
	if (d<dis[x][y]){
		dis[x][y]=d;
		Q.push((node){x,y,d});
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].PB(pii(y,v));
		e[y].PB(pii(x,v));
	}
	memset(dis,30,sizeof(dis));
	dis[1][0]=0;
	Q.push((node){1,0,0});
	while (!Q.empty()){
		node tmp=Q.top(); Q.pop();
		if (vis[tmp.x][tmp.y]) continue;
		vis[tmp.x][tmp.y]=1;
		for (auto i:e[tmp.x]){
			UPD(i.fi,tmp.y,tmp.d+i.se);
			if (!(tmp.y&1)) UPD(i.fi,tmp.y|1,tmp.d);
			if (!(tmp.y&2)) UPD(i.fi,tmp.y|2,tmp.d+2*i.se);
			if (!tmp.y) UPD(i.fi,3,tmp.d+i.se);
		}
	}
	For(i,2,n) printf("%lld ",dis[i][3]);
}