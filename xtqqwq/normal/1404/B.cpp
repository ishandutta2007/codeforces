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

int n,a,b,da,db,ds,tot;
int v[200005],nxt[200005],h[100005],dep[100005],max1[100005],max2[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	max1[u]=max2[u]=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
		if(max1[v[p]]+1>max1[u]) max2[u]=max1[u],max1[u]=max1[v[p]]+1;
		else chkmax(max2[u],max1[v[p]]+1);
	}
	chkmax(ds,max1[u]+max2[u]);
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); a=readint(); b=readint(); da=readint(); db=readint();
		for(int i=1;i<=n;i++) h[i]=0; tot=ds=0;
		for(int i=1;i<n;i++) addedge(readint(),readint());
		dep[a]=1; dfs(a,-1);
		if(dep[b]-1<=da||db<=2*da||ds<=2*da) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}