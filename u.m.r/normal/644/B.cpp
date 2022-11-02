#include<bits/stdc++.h>

using namespace std;

const int MAXN =2e5 + 10;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef pair<PLL, ll> PPL;
ll ans[MAXN];

queue<PPL> Q;

int main(){
	int n, b;
	cin>>n>>b;
	ll now = 0;
	for(int i = 1; i <= n; i++){
		int s, t;
		scanf("%d%d", &s, &t);
		while(!Q.empty() && Q.front().first.second + max(now, Q.front().first.first) <= s){
			now = Q.front().first.second + max(now, Q.front().first.first);
			ans[Q.front().second] = now;
			Q.pop();
		}
		if (Q.size() <= b){
			Q.push(PPL(PLL(s, t), i));
		}
		else
			ans[i] = -1;
	}
	while(!Q.empty()){
		now = Q.front().first.second + max(now, Q.front().first.first);
		ans[Q.front().second] = now;
		Q.pop();
	}
	for(int i = 1; i <= n; i++)
		printf("%lld%c", ans[i], " \n"[i == n]);
	return 0;
}