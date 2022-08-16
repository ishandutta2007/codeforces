#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,tot;
int v[400005],nxt[400005],h[200005],dis[200005],a[200005];
bool vis[200005];
vector<int> fr[200005];
priority_queue<pii> q;

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(mp(0,s));
	while(!q.empty()){
		int t=q.top().se; q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int p=h[t];p;p=nxt[p]){
			if(!vis[v[p]]&&chkmin(dis[v[p]],dis[t]+1)){
				fr[v[p]].clear();
				fr[v[p]].push_back(t);
				q.push(mp(-dis[v[p]],v[p]));
			}
			else if(!vis[v[p]]&&dis[v[p]]==dis[t]+1) fr[v[p]].push_back(t);
		}
	}
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		addedge(y,x);
	}
	k=readint();
	for(int i=1;i<=k;i++) a[i]=readint();
	dij(a[k]);
	int mincnt=0,maxcnt=0;
	for(int i=1;i<k;i++){
		bool fl1=1,fl2=0;
		for(auto x:fr[a[i]]){
			if(x==a[i+1]) fl1=0;
			else fl2=1;
		}
		mincnt+=fl1,maxcnt+=fl2;
	}
	printf("%d %d\n",mincnt,maxcnt);
	return 0;
}