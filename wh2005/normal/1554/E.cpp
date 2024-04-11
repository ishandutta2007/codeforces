#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 998244353;
const int N = 1e6+9;
ll qpow(ll x,ll y){ll t=1;while(y){if(y&1) (t*=x)%=mod;(x*=x)%=mod,y>>=1;}return t;}
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}

int sz[N];

void dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i!=-1;i=g[i].nxt){
		int v=g[i].to;if(v==fa) continue;dfs(v,u);sz[u]+=sz[v];
	}
	return ;
}

ll f[N];

ll chk(int k){
	ll ans=1;
	for(int i=2;i<=n;i++){
		if(sz[i]==1) continue;
		if(((sz[i]-1)%k==0)||(sz[i]%k==0)){
			(ans*=(((sz[i]-1)%k==0)+(sz[i]%k==0)))%=mod;
			continue;
		}
		return 0;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) head[i]=-1,f[i]=0;tot=0;
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
		}
		dfs(1,0);
		for(int k=2;k<=n-1;k++)
			if((n-1)%k==0){
				f[k]=chk(k);
			}
		ll t=0;
		for(int i=n;i>=2;i--){
			for(int j=i+i;j<=n;j+=i) (f[i]+=mod-f[j])%=mod;
			(t+=f[i])%=mod;
		}
		f[1]=(qpow(2,n-1)+mod-t)%mod;
		for(int i=1;i<=n;i++) printf("%lld ",f[i]);puts("");
	}
	return 0;
}
/*



 $a$ 
 $a$  $a$ 
 $a$ 
 $2^{n-1}$ 
 $1$ 
 gcd  
gcd=k 
gcd=1  
 gcd  k 
 gcd  k 
 gcd  1 
 u 
 u 
 u  k 
 u  k  -1  
 gcd  k  1  0

 siz-1  k  k  -1 
 $u$  $a$ 
 a  k  k  u  a 


 siz-1  k 
 
*/