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

const int N = 200010;
int n;
vector<int> G[N];
int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}


int dfs(int num,int fa = -1){
	int ret = 1;
	int cnt = 1;
	for(auto ct:G[num]){
	
		if(ct == fa)continue;
		cnt+=1;
		ret = 1ll*ret*dfs(ct,num)%mod;
		ret = 1ll*cnt*ret%mod;
	}
	return ret;
}
int main() {
	read(n);
	for(int i=1;i<n;i++){
		int u,v;
		read(u);read(v);
		G[u].push_back(v);G[v].push_back(u);
	}
	int cans = dfs(1);
	//cout<<mpow(G[1].size()+1,mod-2)<<endl;
	//cout<<mul(cans,mpow(G[1].size()+1,mod-2))<<endl;
	cans = mul(n,mul(cans,mpow(G[1].size()+1,mod-2)));
	cout<<cans<<endl;
	return 0;
}