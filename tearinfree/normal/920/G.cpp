#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

vector<pii> dp[1000001];
int vis[1000001];

void make_prime() {
	vector<int> prime;
	for(int i=2;i<=1000000;i++) {
		if(!vis[i]) {
			prime.push_back(i);
			for(lli j=1ll*i*i;j<=1000000;j+=i) vis[j]=1;
			
			dp[i].push_back(pii(i,1));
		}
		else {
			for(auto &v:prime) {
				if(i%v==0) {
					dp[i]=dp[i/v];
					int f=0;
					for(auto &t:dp[i]) {
						if(t.first==v) {
							t.second++;
							f=1;
							break;
						}
					}
					if(!f) dp[i].push_back(pii(v,1));
					break;
				}
			}
		}
	}
}

int n,p,k,d;
lli comb[51][51],fact[51];
vector<pair<int,lli>> arr;

void dfs(int idx,int val,int cnt) {
	if(idx==dp[p].size()) {
		arr.push_back(pair<int,int>(val, cnt&1 ? -1 : 1));
	}
	else {
		int v=1;
		for(int i=0;i<=1;i++) {
			dfs(idx+1,val*v,cnt+i);
			v*=dp[p][idx].first;
		}
	}
}
void init() {
	dfs(0,1,0);
	
	d=0;
	for(auto v:arr) {
		d += v.second * (n/v.first);
	}
}
bool check(lli val) {
	lli c=0;
	for(auto v:arr) {
		c += v.second * (val/v.first);
	}
	c-=d+k;
	return c>=0;
}

int main() {
	make_prime();
	
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d%d%d",&n,&p,&k);
		arr.clear();
		init();
	
		lli lo=0,up=4e18;
		while(up-lo>1) {
			lli md=(lo+up)>>1;
			if(check(md)) up=md;
			else lo=md;
		}
		printf("%lld\n",up);
	}
	
	return 0;
}