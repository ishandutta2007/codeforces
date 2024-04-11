#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 5;
const int LIM = 60 + 1;
const int MOD = 1000000007;

int N, M;
int vis[MN];
ll val[MN];
ll p2[5*MN];
vector<pair<int,ll>> E[MN];
vector<ll> cyc;
vector<int> nodes;
int chk[LIM];
int cnt[LIM][2];

int size_basis(vector<ll> &num){
	int n = num.size();
	int j = 0;
	int cnt = 0;
	for(int i=0;i<n && j<LIM;i++){
		if(((1ll<<j)&num[i]) == 0){
			int p = -1;
			for(int k=i+1;k<n;k++){
				if((1ll<<j)&num[k]) p = k;
			}
			if(p == -1){
				j++, i--;
				continue;
			}
			swap(num[i], num[p]);
		}
		cnt++;
		for(int k=i+1;k<n;k++){
			if((1ll<<j)&num[k]) num[k] ^= num[i];
		}
	}
	return cnt;
}

void dfs(int n, ll v){
	vis[n] = 1;
	nodes.push_back(n);
	val[n] = v;
	for(auto &e: E[n]){
		if(vis[e.first]){
			ll pv = val[n] ^ e.second ^ val[e.first];
			if(pv != 0) cyc.push_back(pv);
		}
		else{
			dfs(e.first, v ^ e.second);
		}
	}
}

int main(){
	p2[0] = 1;
	for(int i=1;i<5*MN;i++) p2[i] = 2*p2[i-1] % MOD;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		II(a)II(b); a--,b--;
		ll c;
		scanf("%lld",&c);
		E[a].emplace_back(b, c);
		E[b].emplace_back(a, c);
	}
	ll ans = 0;
	for(int i=0;i<N;i++)if(!vis[i]){
		cyc.clear();
		nodes.clear();
		for(int i=0;i<LIM;i++) chk[i] = cnt[i][0] = cnt[i][1] = 0;
		dfs(i, 0);
		for(auto &v: cyc){
			NDBG printf("cyc %lld\n", v);
			for(int i=0;i<LIM;i++)if(v&(1ll<<i)){
				chk[i] = 1;
			}
		}
		int sz = size_basis(cyc);
		NDBG printf("sz %d\n",sz);
		for(auto &n: nodes){
			for(int i=0;i<LIM;i++){
				int c;
				if(chk[i]){
					ans += p2[i]*(cnt[i][0]+cnt[i][1])%MOD*p2[sz-1]%MOD;
					ans %= MOD;
				}
				else{
					if(val[n]&(1ll<<i))	c = cnt[i][0];
					else c = cnt[i][1];
					ans += p2[i]*c%MOD*p2[sz]%MOD;
					ans %= MOD;
				}
			}
			for(int i=0;i<LIM;i++){
				if(val[n]&(1ll<<i)) cnt[i][1]++;
				else cnt[i][0]++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}