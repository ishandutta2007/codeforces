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

int cnt[1000005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	VI A;
	std::cin >> n;
	A.resize(n);
	ll sum = 0;
	FOR(i, n) std::cin >> A[i], sum += A[i], cnt[A[i]]++;
	VI ans;
	FOR(i, n){
		cnt[A[i]]--;
		sum -= A[i];
		if((sum % 2 == 0 && sum/2 <= 1000000) && cnt[sum/2] > 0) ans.push_back(i);
		cnt[A[i]]++;
		sum += A[i];
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i + 1 << " ";
	return 0;
}