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

int n,tot,ncnt;
int a[1000005],b[1000005],h[1100005],v[2200000],nxt[2200000],id[2200000];
int du[1100000],vis[1100000],ans[1100000],edge[1100000];
vector<int> vec[1100000];

void addedge(int x,int y,int z){
	v[++tot]=y; nxt[tot]=h[x]; id[tot]=z; h[x]=tot; du[x]++; edge[z]=0;
	v[++tot]=x; nxt[tot]=h[y]; id[tot]=z; h[y]=tot; du[y]++;
}

void dfs(int u){
	for(int &p=h[u];p;p=nxt[p]){
		int to=v[p],lab=id[p];
		if(edge[id[p]]) continue;
		edge[id[p]]=1;
		dfs(to);
		ans[++ncnt]=lab;
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[2*i-2]=readint(),a[2*i-1]=readint();
	for(int i=20;i>=1;i--){
		int st=-1,cnt=0;
		for(int j=0;j<n+n;j++){
			b[j]=a[j]&((1<<i)-1);
			vec[b[j]].pb(j);
			st=j;
		}
		int all=0;
		for(int j=1;j<n+n;j++) if(b[j]!=b[j-1]) all=1;
		if(!all){
			printf("%d\n",i);
			for(int i=1;i<=n+n;i++) printf("%d ",i);
			printf("\n");
			return 0;
		}
		for(int j=0;j<(1<<i);j++) h[j]=vis[j]=du[j]=0; tot=0;
		for(int j=0;j<n+n;j+=2)
			if(b[j^1]!=b[j])
				addedge(b[j],b[j^1],j/2),cnt++,st=j;
		if(!cnt) continue;
		bool fl=0;
		for(int j=0;j<(1<<i);j++) if(du[j]&1) fl=1;
		if(fl){
			for(int j=0;j<(1<<i);j++) vec[j].clear();
			continue;
		}
		ncnt=0;
		dfs(b[st]);
		reverse(ans+1,ans+ncnt+1);
		if(ncnt==cnt){
			int pl=st;
			vector<int> res(0);
			for(int i=1;i<=ncnt;i++){
				if(!vis[b[pl]]){
					vis[b[pl]]=1;
					for(auto r:vec[b[pl]])
						if((r&1)&&b[r]==b[r^1]) res.pb(r+1),res.pb((r^1)+1);
				}
				res.pb(pl+1);
				res.pb((pl^1)+1);
				if(i==ncnt) break;
				if(b[pl^1]==b[ans[i+1]*2]) pl=ans[i+1]*2;
				else pl=ans[i+1]*2+1;
			}
			if(res.size()==n+n){
				printf("%d\n",i);
				for(auto r:res) printf("%d ",r);
				printf("\n");
				return 0;
			}
		}
		for(int j=0;j<(1<<i);j++) vec[j].clear();
	}
	printf("0\n");
	for(int i=1;i<=n+n;i++) printf("%d ",i);
	printf("\n");
	return 0;
}