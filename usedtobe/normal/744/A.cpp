#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,v,u) for(int i=H[u],v=to[i];i;i=nxt[i],v=to[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inf 10000000
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=111111;
//head
int n,t,m,SZ,D;
bool vis[N],ok[N];
int f[N],sz[N],d[N];
int get(int x) {return f[x]==x?x:f[x]=get(f[x]);}
int main() {
	read(n,m,t);
	rep(i,1,t){
		int x;read(x);vis[x]=1;
	}
	rep(i,1,n)sz[i]=1,f[i]=i;
	rep(i,1,m){
		int x,y;read(x,y);
		int p=get(x),q=get(y);
		if(p==q){d[p]++;continue;}
		if(vis[p])f[q]=p,sz[p]+=sz[q],d[p]+=d[q]+1;
		else f[p]=q,sz[q]+=sz[p],d[q]+=d[p]+1;
	}
	int ans=0,mx=0;
	rep(i,1,n){
		int p=get(i);
		if(ok[p])continue;
		ok[p]=1;
		if(!vis[p]){
			SZ+=sz[p];D+=d[p];
		}else {
			if(mx<sz[p])mx=sz[p];
			ans+=sz[p]*(sz[p]-1)/2-d[p];
		}
	}
	ans+=(SZ-1)*SZ/2-D;
	ans+=mx*SZ;
	printf("%d\n",ans);
	return 0;
}