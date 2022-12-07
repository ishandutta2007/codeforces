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
const int N=500005;
struct node{
	int x,y,v;
};
node p[N];
vector<node> e[N];
int vis[N],id1[N],id2[N],n;
int sx,sy,tx,ty;
ll d[N];
priority_queue<pll> Q; 
bool cmp1(int x,int y){
	return pii(p[x].x,p[x].y)<pii(p[y].x,p[y].y);
}
bool cmp2(int x,int y){
	return pii(p[x].y,p[x].x)<pii(p[y].y,p[y].x);
}
void add(int x,int y){
	int d=min(abs(p[x].x-p[y].x),abs(p[x].y-p[y].y));
	e[x].PB((node){x,y,d});
	e[y].PB((node){y,x,d});
}
int main(){
	scanf("%*d%d",&n);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	For(i,1,n){
		scanf("%d%d",&p[i].x,&p[i].y);
		id1[i]=id2[i]=i;
	}
	sort(id1+1,id1+n+1,cmp1);
	sort(id2+1,id2+n+1,cmp2);
	For(i,2,n){
		add(id1[i-1],id1[i]);
		add(id2[i-1],id2[i]);
	}
	For(i,1,n){
		d[i]=min(abs(sx-p[i].x),abs(sy-p[i].y));
		Q.push(pll(-d[i],i)); 
	} 
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		//cerr<<x<<endl;
		if (vis[x]) continue;
		vis[x]=1;
		for (auto i:e[x])
			if (d[i.y]>d[i.x]+i.v)
				d[i.y]=d[i.x]+i.v,
				Q.push(pll(-d[i.y],i.y));
	}
	ll ans=abs(sx-tx)+abs(sy-ty);
	For(i,1,n) ans=min(ans,d[i]+abs(tx-p[i].x)+abs(ty-p[i].y));
	cout<<ans<<endl;
}