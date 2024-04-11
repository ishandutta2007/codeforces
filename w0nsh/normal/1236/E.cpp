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

VI get(int n, int m, VI A){
	std::set<PII> set;
	VI next(m, m);
	int add = 0;
	FOR(i, m){
		while(true){
			auto it = set.lower_bound(MP(A[i]-add, -1));
			if(it != set.end() && it->X == A[i]-add){
				next[it->Y] = i;
				set.erase(it);
			}else break;
		}
		add++;
		set.insert(MP(A[i]-add, i));
	}
	VI val(m+1, 1);
	for(int i = m-1; i >= 0; --i){
		val[i] = val[next[i]] + next[i]-i-1;
	}
	VI ile(n, -1);
	VI ddd(n, 0);
	FOR(i, m){
		int kto = A[i]-i-1;
		if(kto < 0 || ile[kto] != -1) continue;
		ile[kto] = i;
		ddd[kto] = i;
	}
	ll all = 0;
	VI ret(n);
	FOR(i, n){
		int cur = 0;
		if(ile[i] == -1) cur = std::min(m+2, n-1-i+1);
		else{
			cur = std::min(std::min(m+2, n-1-i+1), 1+val[ile[i]]+ddd[i]);
		}
		all += cur;
		ret[i] = cur;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	if(n == 1){
		std::cout << 0;
		return 0;
	}
	VI A(m);
	FOR(i, m) std::cin >> A[i];
	FOR(i, m) A[i]--;
	VI a = get(n, m, A);
	VI XD(m);
	FOR(i, m) XD[i] = n-1-A[i];
	VI b = get(n, m, XD);
	FOR(i, n-1) assert(a[i] > 1);
	FOR(i, n-1) assert(b[i] > 1);
	std::reverse(b.begin(), b.end());
	VI ans(n);
	ll sum = 0;
	FOR(i, n) ans[i] = b[i]+a[i]-1, sum += ans[i];
	std::cout << sum;
	return 0;
}