#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n;
VI A, cnt, first, last, ans;
std::set<int> todo;
std::vector<bool> used;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	cnt.resize(n);
	first.resize(n, -1);
	last.resize(n);
	used.resize(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n){
		cnt[--A[i]]++;
		if(first[A[i]] == -1) first[A[i]] = i;
		last[A[i]] = i;
	}
	int zmn = 0;
	FOR(i, n) if(cnt[i] == 0) todo.insert(i);
	FOR(i, n){
		if(cnt[A[i]] > 1){
			if(!used[A[i]] && last[A[i]] == i) ans.push_back(A[i]);
			else if(!used[A[i]] && *todo.begin() > A[i]){
				used[A[i]] = true;
				ans.push_back(A[i]);
			}
			else{
				zmn++;
				ans.push_back(*todo.begin());
				todo.erase(todo.begin());
			}
		}else ans.push_back(A[i]);
	}
	std::cout << zmn << "\n";
	TRAV(i, ans) std::cout << i+1 << " ";
	return 0;
}