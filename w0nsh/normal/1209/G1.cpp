#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int repr[200005], last[200005];
std::vector<VI> vec;

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}
int Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(SZ(vec[a]) > SZ(vec[b])) std::swap(a, b);
	last[b] = std::max(last[b], last[a]);
	repr[a] = b;
	while(SZ(vec[a])) vec[b].push_back(vec[a].back()), vec[a].pop_back();
	return b;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, q;
	std::cin >> n >> q;
	vec.resize(200005);
	FOR(i, 200005) repr[i] = i, last[i] = -1, vec[i].push_back(i);
	std::map<int, int> ile;
	VI A(n);
	FOR(i, n) std::cin >> A[i], last[A[i]] = i, ile[A[i]]++;
	int pos = 0;
	while(pos < n){
		int my = Find(A[pos]);
		int upto = last[my];
		while(pos <= upto){
			int cur = Find(A[pos]);
			if(cur != my){
				my = Union(cur, my);
				upto = last[my];
			}
			pos++;
		}
	}
	int ans = 0;
	std::set<int> vis;
	FOR(i, n){
		int kto = Find(A[i]);
		if(vis.count(kto) == 0){
			vis.insert(kto);
			int maks = 0;
			int all = 0;
			TRAV(j, vec[kto]){
				maks = std::max(maks, ile[j]);
				all += ile[j];
			}
			ans += all-maks;
		}
	}
	std::cout << ans;
	return 0;
}