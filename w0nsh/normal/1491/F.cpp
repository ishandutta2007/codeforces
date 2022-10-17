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

int query(const VI& A, const VI& B){
	std::cout << "? " << SZ(A) << " " << SZ(B) << std::endl;
	TRAV(i, A) std::cout << i+1 << " ";
	std::cout << std::endl;
	TRAV(i, B) std::cout << i+1 << " ";
	std::cout << std::endl;
	int f;
	std::cin >> f;
	return f;
}

void solve(){
	int n;
	std::cin >> n;
	VI A{n-1};
	VI B;
	int pos = -1;
	for(int i = n-2; i >= 0; --i){
		B = VI{i};
		int f = query(A, B);
		if(f){
			pos = i;
			break;
		}
		A.push_back(i);
	}
	if(pos == -1){
		while(true);
	}
	std::vector<bool> ans(n, true);
	ans[pos] = false;
	A = VI{pos};
	B = VI();
	FOR(i, pos){
		B.push_back(i);
		if(query(A, B)){
			ans[i] = false;
		}
		B.pop_back();
	}
	int left = pos+1;
	int right = n-1;
	B = VI();
	while(left < right){
		int mid = (left+right)/2;
		B = VI();
		REP(i, left, mid+1){
			B.push_back(i);
		}
		if(query(A, B)){
			right = mid;
		}else{
			left = mid+1;
		}
	}

	ans[left] = false;

	int cnt = 0;
	FOR(i, n) if(ans[i]) cnt++;
	assert(cnt > 0);
	std::cout << "! " << cnt;
	FOR(i, n) if(ans[i]){
		std::cout << " " << i+1;
	}
	std::cout << std::endl;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}