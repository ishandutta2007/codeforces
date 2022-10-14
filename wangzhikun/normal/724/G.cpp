//determined
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <complex>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}


const int N = 200040;
vector<pll> G[N];
ll n,m,u,v,w,vis[N],xs[N],base[100],s[N],sn;

ll mod = 1000000007,pw2[200],szb;

void add(ll num){
	//cout<<"add "<<num<<endl;
	for (int j = 60; j >= 0; --j)
		if (num >> j & 1) {
			if (base[j]) num ^= base[j];
			else {
				szb+=1;
				base[j] = num;
				for (int k = j - 1; k >= 0; --k) if (base[k] && (base[j] >> k & 1)) base[j] ^= base[k];
				for (int k = j + 1; k <= 60; ++k) if (base[k] >> j & 1) base[k] ^= base[j];
				break;
			}
		}
}
void dfs(int num,ll cd){
	s[sn] = num;sn+=1;
	vis[num] = 1;
	xs[num] = cd;
	for(auto cw:G[num]){
		ll cto = cw.first, cxs = cw.second;
		if(!vis[cto]){
			dfs(cto,cxs^cd);
		}else{
			add(xs[cto]^xs[num]^cxs);
		}
	}
}

int main(){
	pw2[0] = 1;
	for(int i=1;i<200;i++)pw2[i] = 2*pw2[i-1]%mod;
	read(n);read(m);
	for(int i=0;i<m;i++){
		read(u);read(v);read(w);
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	ll ans = 0;
	for(int ech=1;ech<=n;ech++){
		if(vis[ech])continue;
		szb = sn = 0;
		memset(base,0,sizeof(base));
		dfs(ech,0);
	
		for(int i=0;i<60;i++){
			ll x = 0;
			for(int j=0;j<60;j++){
				if((base[j]>>i)&1){
					ans = (ans+((sn*(sn-1)/2)%mod)*pw2[szb-1+i])%mod;
					goto nxt;
				}
			}
			for(int j=0;j<sn;j++){
				x+=(((xs[s[j]]>>i)&1) == 0);
			}
			//cout<<i<<' '<<sn<<' '<<x<<endl;
			ans = (ans+((x*(sn-x))%mod)*pw2[szb+i])%mod;
		nxt:;
		}
	}
	cout<<ans<<endl;
	return 0;
}