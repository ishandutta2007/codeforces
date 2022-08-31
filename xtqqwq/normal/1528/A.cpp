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

int n,tot;
int v[200005],nxt[200005],h[100005];
ll l[100005],r[100005],d[100005][2];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	d[u][0]=d[u][1]=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		d[u][0]+=max(d[v[p]][0]+abs(l[u]-l[v[p]]),d[v[p]][1]+abs(l[u]-r[v[p]]));
		d[u][1]+=max(d[v[p]][0]+abs(r[u]-l[v[p]]),d[v[p]][1]+abs(r[u]-r[v[p]]));
	}
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) l[i]=readint(),r[i]=readint();
		for(int i=1;i<=n;i++) h[i]=0; tot=0;
		for(int i=1;i<n;i++) addedge(readint(),readint());
		dfs(1,-1);
		printf("%lld\n",max(d[1][0],d[1][1]));
	}
	return 0;
}