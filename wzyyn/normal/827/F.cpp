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
const int INF=(1<<30);
const int N=500005;
vector<pii> v[N*2];
vector<int> id[N*2];
struct edge{
	int to,next,l,r;
}e[N*12];
int head[N*4],tot;
int dis[N*4],vis[N*4];
int n,m,nd,x[N],y[N],l[N],r[N]; 
priority_queue<pii> Q;
void insert(int x,int fl,int l,int r){
	l+=(l+fl)&1; r-=(r+fl)&1;
	v[x*2+fl].PB(pii(l,r));
}
void add(int x,int y,int l,int r){
	//printf("%d %d %d %d\n",x,y,l,r);
	e[++tot]=(edge){y,head[x],l,r};
	head[x]=tot;
}
int find(const vector<pii> &v,int val){
	int l=0,r=v.size()-1,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (v[mid].se>=val)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
void add(int x,int flx,int y,int fly,int l,int r){
	int L=l,R=r;
	l+=(l+flx)&1; r-=(r+flx)&1;
	int xid=2*x+flx,yid=2*y+fly;
	int s=find(v[xid],l),t=find(v[yid],l);
	if (v[yid][t].fi<=R) add(id[xid][s],id[yid][t],l,min(v[yid][t].se,R)-1);
	if (v[xid][s].se<R&&v[xid][s].se+1==v[yid][t+1].fi)
		add(id[xid][s],id[yid][t+1],r,r);
}
void SSSP(){
	For(i,1,nd) dis[i]=1<<30,vis[i]=0;
	assert(id[2].size());
	int S=id[2][0];
	Q.push(pii(dis[S]=0,S));
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (dis[x]<=e[i].r){
				int val=max(e[i].l,dis[x])+1;
				if (val<dis[e[i].to])
					Q.push(pii(-(dis[e[i].to]=val),e[i].to));
			}
	}
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	if (n==1) return puts("0"),0;
	For(i,1,m){
		scanf("%d%d%d%d",&x[i],&y[i],&l[i],&r[i]);
		insert(x[i],0,l[i],r[i]);
		insert(x[i],1,l[i],r[i]);
		insert(y[i],0,l[i],r[i]);
		insert(y[i],1,l[i],r[i]);
	}
	v[2].PB(pii(0,0));
	For(i,2,2*n+1){
		if (!v[i].size()) continue;
		int sz=v[i].size();
		sort(v[i].begin(),v[i].end());
		//printf("INFO %d\n",i);
		//for (auto j:v[i]) cout<<j.fi<<' '<<j.se<<endl;
		int top=0,l=v[i][0].fi,r=v[i][0].se;
		For(j,1,sz-1){
			if (r<v[i][j].fi){
				v[i][top++]=pii(l,r);
				id[i].PB(++nd);
				l=v[i][j].fi;
			}
			r=max(r,v[i][j].se);
		}
		v[i][top++]=pii(l,r);
		id[i].PB(++nd);
		v[i].resize(top);
		v[i].PB(pii(INF,INF));
	}
	For(i,1,m){
		add(x[i],0,y[i],1,l[i],r[i]); 
		add(x[i],1,y[i],0,l[i],r[i]); 
		add(y[i],0,x[i],1,l[i],r[i]); 
		add(y[i],1,x[i],0,l[i],r[i]); 
	}
	SSSP();
	int ans=1<<30;
	For(i,n*2,n*2+1)
		for (auto j:id[i])
			ans=min(ans,dis[j]);
	printf("%d\n",ans==1<<30?-1:ans);
}