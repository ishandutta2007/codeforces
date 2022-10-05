#include<bits/stdc++.h>

const int N = 64;
const int M = 100010;

typedef long long ll;

int highbit(ll n){
	int ret = 0;
	while (n){
		++ ret;
		n >>= 1;
	}
	return ret - 1;
}

std::queue <ll> queue[N];
ll b[M];
std::vector <ll> ans;

void dfs(int hb, ll &nowa){
	if (hb < 0) return;
	if (!hb){
		if ((nowa & 1) && !queue[hb].empty()){
			ll x = queue[hb].front();
			ans.push_back(x);
			nowa ^= x;
			queue[hb].pop();
		}
		return;
	}
	if (!(nowa >> hb & 1) || queue[hb].empty()){
		dfs(hb - 1, nowa);
		return;
	}
	dfs(hb - 1, nowa);
	ll x = queue[hb].front();
	ans.push_back(x);
	nowa ^= x;
	queue[hb].pop();
	dfs(hb - 1, nowa);
}

int main(){
	int n;
	scanf("%d", &n);
	int max = 0;
	ll nowa = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%I64d", &b[i]);
		int hb = highbit(b[i]);
		queue[hb].push(b[i]);
		nowa ^= b[i];
	}
	dfs(highbit(nowa), nowa);
	for (int i = 0; i < N; ++ i){
		if (!queue[i].empty()){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	std::reverse(ans.begin(), ans.end());
	for (int i = 0, sz = ans.size(); i < sz; ++ i){
		printf("%I64d ", ans[i]);
	}
	putchar('\n');
	return 0;
}