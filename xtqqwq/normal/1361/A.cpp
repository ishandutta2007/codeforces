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

int n,m;
int b[500005],ans[500005],vis[500005];
pii a[500005];
vector<int> adj[500005];

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].pb(y),adj[y].pb(x);
	}
	for(int i=1;i<=n;i++) a[i].fi=b[i]=readint(),a[i].se=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int u=a[i].se;
		for(int j=1;j<=adj[u].size()+1;j++) vis[j]=0;
		for(auto v:adj[u]) vis[b[v]]=1;
		int res=0;
		for(int j=1;j<=adj[u].size()+1;j++){
			if(!vis[j]){
				res=j;
				break;
			}
		}
		if(res!=b[u]) return printf("-1\n"),0;
		ans[i]=u;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}