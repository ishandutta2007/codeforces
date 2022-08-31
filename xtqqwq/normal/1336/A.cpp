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

int n,k,tot;
int v[400005],nxt[400005],h[200005],siz[200005],dep[200005],a[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dep[1]=1; dfs(1,-1);
	for(int i=1;i<=n;i++) a[i]=dep[i]-siz[i];
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=n-k+1;i<=n;i++) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}