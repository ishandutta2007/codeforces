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
int p[1000005],v[1000005],nxt[1000005],c[1000005],id[1000005],h[500005],now[500005];
vector<int> vec[500005];
bool vis[500005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; id[tot]=1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; id[tot]=0; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(now[c[p]]<0) now[c[p]]=id[p];
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		dfs(v[p]);
	}
}

int main(){
	n=readint();
	if(n%2==0){
		printf("First\n");
		fflush(stdout);
		for(int i=1;i<=n+n;i++) printf("%d ",i<=n?i:i-n);
		printf("\n");
		fflush(stdout);
	}
	else{
		printf("Second\n");
		fflush(stdout);
		for(int i=1;i<=n+n;i++) p[i]=readint();
		for(int i=1;i<=n+n;i++) vec[p[i]].pb(i);
		for(int i=1;i<=n;i++) addedge(vec[i][0]%n,vec[i][1]%n,i),now[i]=-1;
		for(int i=0;i<n;i++){
			if(!vis[i]){
				vis[i]=1;
				dfs(i);
			}
		}
		ll sum=0;
		for(int i=1;i<=n;i++) sum=(sum+vec[i][now[i]])%(n+n);
		if(sum==0){
			for(int i=1;i<=n;i++) printf("%d ",vec[i][now[i]]);
			printf("\n");
			fflush(stdout);
		}
		else{
			for(int i=1;i<=n;i++) printf("%d ",vec[i][now[i]^1]);
			printf("\n");
			fflush(stdout);
		}
	}
	return 0;
}