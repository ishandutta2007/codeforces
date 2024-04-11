//by xay5421 2449670833@qq.com
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int>pii;typedef vector<int>VI;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}

const int N=200005;
int T,n,sz[N],ans1,ans2;

int lnk[N],pp;
struct ed{int nxt,to,w;}G[N<<1];
void ae(int u,int v,int w){G[++pp]=(ed){lnk[u],v,w},lnk[u]=pp;}

void dfs(int k1,int k2){
	sz[k1]=1;
	for(int i=lnk[k1];i;i=G[i].nxt){
		int j=G[i].to;
		if(j!=k2){
			dfs(j,k1);
			sz[k1]+=sz[j];
			if(sz[j]&1){
				ans1+=G[i].w; 
			}
			ans2+=1ll*G[i].w*min(sz[j],n-sz[j]);
		}
	}
}

signed main(){
	rd(T);
	while(T--){
		rd(n);n*=2;
		for(int i=1,k1,k2,k3;i<n;++i){
			rd(k1),rd(k2),rd(k3);
			ae(k1,k2,k3);
			ae(k2,k1,k3);
		}
		dfs(1,0);
		pt(ans1,' ');
		pt(ans2,'\n');
		for(int i=1;i<=n;++i)lnk[i]=0;pp=0;
		ans1=0,ans2=0;
	}
	return 0;
}