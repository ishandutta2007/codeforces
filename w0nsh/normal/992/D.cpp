#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

const ll LINF = 2000005000000000666ll;
const int INF = 2000000666;
ll n, k;
int next[200005];
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	A.resize(n+1);
	FOR(i, n) std::cin >> A[i];
	A[n] = -1;
	next[n] = n;
	for(int i = n-1; i >= 0; --i) next[i] = (A[i+1] != 1 ? i+1 : next[i+1]);
	int ans = 0;
	FOR(i, n){
		ll p, s;
		p = s = A[i];
		int j = i;
		while(j < n){
			if(p%k == 0 && p/k >= s && p/k <= s + next[j]-j-1) ans++; 
			s += next[j]-j-1;
			j = next[j];
			if(j == n) break;
			s += A[j];
			if(p >= LINF / A[j]) break;
			p *= A[j];
		}
	}
	std::cout << ans << "\n";
	return 0;
}