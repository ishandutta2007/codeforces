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

const int MOD = 998244353;

int need = 0;
int last = 0;
void dfs(int left, int cur=0){
	if(left > 0) dfs(left-1, 1-cur);
	if(last == cur) need++;
	last = cur;
	if(left > 0) dfs(left-1, cur);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int ile = 0;
	while((1<<(ile+1))-1 <= n) ile++;
	int mam = (1<<ile)-1;
	last = ile%2;
	dfs(ile-1, 0);
	//std::cout << mam << " + " << need << " +1/0\n";
	if(n == mam+need || n == mam+need+1) std::cout << 1;
	else std::cout << 0;
	return 0;
}