#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 1e9+7;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int n,ans = 0;
ll val[100010],depth[100010],fgcd[100010] = {0};
vector<int> G[100010];
vector<pii> cv[100010];

void dfs(int num,int fa = 0){
	ans = (val[num]+ans)%mod;
	cv[num].push_back(make_pair(depth[num],val[num]));
	for(auto ct:cv[fa]){
		ll cc = gcd(ct.second,val[num]);
		if(cv[num][cv[num].size()-1].second == cc){
			ans = (ans+cc*(cv[num][cv[num].size()-1].first-ct.first))%mod;
			cv[num][cv[num].size()-1].first = ct.first;
		}else{
			cv[num].push_back(make_pair(ct.first,cc));
			ans = (ans+(cv[num][cv[num].size()-1].second)*(cv[num][cv[num].size()-2].first-cv[num][cv[num].size()-1].first))%mod;
		}
	}
	for(auto ct:G[num]){
		if(ct == fa)continue;
		depth[ct] = depth[num]+1;
		dfs(ct,num);
	}
}

int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(val[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}