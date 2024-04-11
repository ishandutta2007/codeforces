#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	std::multiset<ll> set;
	ll sum = 0;
	FOR(i, n) std::cin >> A[i], set.insert(A[i]), sum += A[i];

	std::priority_queue<ll> que;
	que.push(sum);
	bool bad = false;
	while(SZ(que)){
		auto top = que.top();
		que.pop();

		auto it = set.find(top);
		if(it != set.end()){
			set.erase(it);
			continue;
		}

		if(top < *std::prev(set.end())){
			bad = true;
			break;
		}

		if(top == 1){
			bad = true;
			break;
		}

		que.push(top / 2);
		que.push((top + 1) / 2);
	}

	if(bad || SZ(set)) std::cout << "NO\n";
	else std::cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}