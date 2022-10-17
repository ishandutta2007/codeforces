//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=100005;

int n,m,fa[N],pre[N],nxt[N];std::vector<int>g[N];bool qaq[N],vis[N],tmp[N];

int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}

void era(int i){
	vis[i]=1,nxt[pre[i]]=nxt[i],pre[nxt[i]]=pre[i];
}

signed main(){
	rd(n),rd(m);
	rep(i,1,m){
		int u,v;rd(u),rd(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(i,1,n)pre[i]=i-1,nxt[i]=i+1;nxt[n]=0;
	std::queue<int>q;
	int ans=0;
	rep(i,1,n)if(!vis[i]){
		++ans;
		q.push(i);era(i);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int j=0;j<(int)g[u].size();++j){
				int v=g[u][j];
				tmp[v]=1;
			}
			for(int j=nxt[0];j;j=nxt[j]){
				if(!tmp[j]&&!vis[j]){
					q.push(j);
					era(j);
				}
			}
			for(int j=0;j<(int)g[u].size();++j){
				int v=g[u][j];
				tmp[v]=0;
			}
		}
	}
	pt(ans-1,'\n');
	return 0;
}