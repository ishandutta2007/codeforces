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

const int MOD = 1000000007;
const int INF = 2000000666;

int n, b, a, ans;
std::vector<PII> A;
std::vector<PII> events;

// struct Tree{
// 	std::vector<int> t;
// 	int BOTTOM;
// 	void prop(int v=1){
// 		if(v < BOTTOM){
// 			prop(v<<1);
// 			prop((v<<1)+1);
// 			t[v] = std::min(t[v<<1], t[(v<<1)+1]);
// 		}
// 	}
// 	void build(int size, VI &vec){
// 		BOTTOM = 1;
// 		while(BOTTOM < size) BOTTOM *= 2;
// 		t.resize(BOTTOM*2);
// 		FOR(i, size) t[BOTTOM+i] = vec[i];
// 		REP(i, size, BOTTOM) t[BOTTOM+i] = INF;
// 		prop();
// 	}

// 	int query(int a, int b, int v=1, int lo=0, int hi=-2){
// 		if(hi == -2) hi = BOTTOM-1;
// 		if(a > b) return INF;
// 		if(a == lo && b == hi) return t[v];
// 		int mid = (lo+hi)/2;
// 		return std::min(query(a, std::min(b, mid), v<<1, lo, mid),
// 				query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
// 	}
// };

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> b >> a;
	A.resize(n);
	FOR(i, n){
		std::cin >> A[i].X >> A[i].Y;
		A[i].Y++;
		ans = (1ll*(A[i].Y-A[i].X-1)*a+ans)%MOD;
	}
	FOR(i, n){
		events.push_back(MP(A[i].X, 1));
		events.push_back(MP(A[i].Y, -1));
	}
	std::sort(events.begin(), events.end());
	std::priority_queue<int> ends;
	auto it = events.begin();
	while(it != events.end()){
		if(it->Y == -1) ends.push(it->X);
		else{
			if(SZ(ends) > 0 && 1ll*(it->X-ends.top()+1)*a < b){
				ans = ((1ll*(it->X-ends.top()+1)*a)+ans)%MOD;
				ends.pop();
			}else{
				ans = (ans+b)%MOD;
			}
		}
		it++;
	}
	std::cout << ans << "\n";
	return 0;
}