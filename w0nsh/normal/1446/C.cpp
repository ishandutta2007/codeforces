#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n;
VI A;

int rec(int a, int b, int bit){
	if(a == b) return 0;
	// std::cout << a << " " << b << std::endl;
	assert(bit >= 0);
	
	auto s = A.begin() + a;
	auto e = A.begin() + (b+1);
	auto it = std::lower_bound(s, e, 1<<bit);
	REP(i, a, b+1) if(A[i] & (1<<bit)) A[i] ^= (1<<bit);
	if(it == s || it == e) return rec(a, b, bit-1);

	int pos = it - A.begin();
	assert(pos > a && pos <= b);
	return std::min(rec(a, pos-1, bit-1) + b-pos+1 - 1, rec(pos, b, bit-1) + pos-a - 1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];

	std::sort(A.begin(), A.end());
	std::cout << rec(0, n-1, 30) << "\n";

	return 0;
}