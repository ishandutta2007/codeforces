#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM = 2e6;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = (int)round(sqrt(LIM)), R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
		rep(i,0,min(S, R - L))
			if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr) isPrime[i] = 1;
	return pr;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    vi primes = eratosthenes();

    int t;
    cin>>t;
    vi ans(t,-9);
    vector<pii> queries(t);
    rep(i,0,t) {
        cin>>queries[i].first;
        queries[i].second = i;
    }
    sort(all(queries));
    
    vi event(LIM);
    int cnt = 0;
    int tt = 0;
    rep(i,1,LIM) {
        cnt += event[i];
        if(isPrime[i] || i == 1) {
            ++cnt;
            if(i*1LL*i < LIM) event[i*i] -= 1;
        }
        while(tt < sz(queries) && queries[tt].first == i) {
            ans[queries[tt].second] = cnt;
            ++tt;
        }
    }

    rep(i,0,t) cout << ans[i] << "\n";
}