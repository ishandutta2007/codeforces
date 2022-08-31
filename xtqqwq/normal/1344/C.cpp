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
int du[200005],q[200005],min1[200005],min2[200005];
char ans[200005];
bool vis[200005];
vector<int> adj[200005];

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].pb(y); du[y]++;
	}
	int front=0,rear=0;
	for(int i=1;i<=n;i++) if(!du[i]) q[rear++]=i;
	while(front<rear){
		int t=q[front++];
		for(auto v:adj[t]) if(!(--du[v])) q[rear++]=v;
	}
	if(rear<n) return printf("-1\n"),0;
	memset(min1,0x3f,sizeof(min1));
	memset(min2,0x3f,sizeof(min2));
	for(int i=0;i<=n-1;i++) for(auto v:adj[q[i]]) chkmin(min1[v],min(min1[q[i]],q[i]));
	for(int i=n-1;i>=0;i--) for(auto v:adj[q[i]]) chkmin(min2[q[i]],min(min2[v],v));
	for(int i=1;i<=n;i++) ans[i]='E';
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=n;i++) if(min1[i]>i&&min2[i]>i) ans[i]='A',cnt++;
	printf("%d\n",cnt);
	puts(ans+1);
	return 0;
}