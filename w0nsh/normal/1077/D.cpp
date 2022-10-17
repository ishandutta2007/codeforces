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

int n, k, cnt[200005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	FOR(i, n){
		int a;
		std::cin >> a;
		cnt[a]++;
	}
	std::vector<PII> A;
	FOR(i, 200005){
		if(cnt[i] > 0){
			A.push_back(MP(cnt[i], i));
		}
	}
	std::sort(A.begin(), A.end());
	std::vector<int> ans;
	int left = 1;
	int right = n+1;
	while(left < right){
		int mid = (left+right)/2;
		int have = 0;
		FOR(i, SZ(A)) have += A[i].X/mid;
		if(have >= k) left = mid+1;
		else right = mid;
	}
	int good = left-1;
	int done = 0;
	FOR(i, SZ(A)){
		while(done < k){
			if(A[i].X >= good) A[i].X -= good, std::cout << A[i].Y << " ", done++;
			else break;
		}
	}
	return 0;
}