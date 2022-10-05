#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,m,k,deg[MAXN+5],vis[MAXN+5];
vector<int> g[MAXN+5];
void clear(){
	for(int i=1;i<=n;i++) deg[i]=vis[i]=0;
	for(int i=1;i<=n;i++) g[i].clear();
}
bool getedg(int x,int y){
	int l=0,r=-1+(int)(g[x].size());
	while(l<=r){
		int mid=l+r>>1;
		if(g[x][mid]==y) return 1;
		else if(g[x][mid]-y>>31) l=mid+1;
		else r=mid-1;
	} return 0;
}
void solve(){
	scanf("%d%d%d",&n,&m,&k);clear();
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);deg[u]++;deg[v]++;
		g[u].pb(v);g[v].pb(u);
	} queue<int> q;
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	for(int i=1;i<=n;i++) if(deg[i]<k) q.push(i),vis[i]=1;
	while(!q.empty()){
		int x=q.front();q.pop();vis[x]=2;
		if(deg[x]==k-1){
			vector<int> vec;
			for(int y:g[x]){
				if(vis[y]==2) continue;vec.pb(y);
			} bool flg=1;
			for(int i=0;i<vec.size();i++){
				for(int j=0;j<i;j++)
					if(!getedg(vec[i],vec[j])){flg=0;break;}
				if(!flg) break;
			}
			if(flg){
				puts("2");
				for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);
				return printf("%d\n",x),void();
			}
		}
		for(int y:g[x]) if(--deg[y]==k-1&&!vis[y]) q.push(y);
	}
	vector<int> ans;
	for(int i=1;i<=n;i++) (!vis[i]&&(ans.pb(i),1));
	if(!ans.size()) return puts("-1"),void();
	printf("1 %d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}