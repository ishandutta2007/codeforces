#include <algorithm>
#include <unordered_set>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <ostream>
#include <istream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
const int64_t inf = 1e12;
using namespace std;
#define ll long long
#define sz(s) (int(s.size()))
#define all(x) x.begin(),x.end()
#define sum(x) accumulate(x.begin(), x.end(), 0LL)
#define vec vector
#define nl '\n'
#define fn function
#define vt vec
#define vl vt<ll>
#define vi vector<int64_t>
#define pr pair
#define pll pr<ll,ll>
#define pii pair<int32_t, int32_t>
#define it int64_t



template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
#define rep(i, a,b) for(int i = a; i < b; i++)
#define dep(i, a,b) for(int i = a-1; i >= b; i--)
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define space " "
// #define end nl
#define pv print_vec


template<class T> void print_vec(vector<T> &a) {
    for(auto &num: a)
        cout << num << space;
	cout << "\n";
    // cout << end;
}


int const alpha = 26;
int const hp = 200;
int const big_int = 10000;
int const bigm = 100000;
int const bign = 200000;
int const big_graph = 500000;
int const bigbig = 1e7;

void run_case()
{
	int N; cin >> N;
	string S; cin >> S;

	map<pii, int> mp;

	pair<int, int> cur(0, 0);

	vector<pair<int, int>> ans;
	mp[{0, 0}] = 0;
	for(int i = 0; i < N; i++) {
		char c = S[i];
		int p = i + 1;

		if(S[i] == 'L') {
			cur.first--;
		}
		if(c == 'R') {
			cur.first++;
		}
		if(c == 'U') {
			cur.second++;
		}
		if(c == 'D') {
			cur.second--;
		}
		if(mp.find(cur) != mp.end()) {
			ans.push_back({mp[cur], p});
		}
		mp[cur] = p;
	}

	sort(ans.begin(), ans.end(), [](const auto a, const auto b) {
		return a.second - a.first < b.second - b.first;
	});
	if(sz(ans)) {
		cout << ans[0].first + 1 << " " << ans[0].second << "\n";
		return;
	}
	

	cout << -1 << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--)
		run_case();
}


// 10 nhours at least 
// so basically 6 more hours are neede
// 
// ve - nb - be/2
//    #include<iostream>