#include <bits/stdc++.h>
#define ll long long
#define FOR(i, n) for(int i =0; i  < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define PR std::pair
#define PII std::pair<int, int>
#define SZ(i) ((int)((i).size()))
#define VI std::vector<int>
#define MP std::make_pair
#define X first
#define Y second

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::vector<PII> A;
	std::cin >> n >> k;
	A.resize(n);
	FOR(i, n) std::cin >> A[i].X, A[i].Y = i;
	std::sort(A.begin(), A.end());
	std::map<int, int> skill;
	FOR(i, n) skill[A[i].Y] = A[i].X;
	VI ans(n);
	FOR(i, k){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(skill[a] < skill[b]) ans[b]--;
		else if(skill[a] > skill[b]) ans[a]--;
	}
	int same = 0;
	FOR(i, n){
		if(i>0 && A[i].X == A[i-1].X) same++;
		else same = 0;
		ans[A[i].Y] += i-same;
	}
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}