#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ar array


vector<int> G[15];
vector<int> colors(15);
vector<int> toposort;
vector<bool> v(15);
bool works = true;

void dfs(int cur) {
	if(v[cur]) return;
	v[cur]=true;
	colors[cur]=1;

	for(auto edge: G[cur]) {
		if(colors[edge]==1) {
			works = false;
			return;
		}
		if(!v[edge]) {
			if(colors[edge]==1) {
				works = false;
				return;
			} else {
				dfs(edge);
			}
		}
	}
	toposort.push_back(cur);
	colors[cur]=2;
}
void solve() {
	int N = 3;

	for(int i = 0; i < N; i++) {
		string t;
		cin >> t;

		if(t[1] == '<')
			swap(t[0], t[2]);

		int res1 = t[0]-'A';
		int res2 = t[2]-'A';

		G[res1].push_back(res2);
	}

	for(int i = 0; i < 3; i++) {
		if(!v[i]) dfs(i);
	}
	
	if(toposort.size() < 3 || !works) {
		cout << "Impossible\n";
		return;
	}
	for(int i = 0; i < 3; i++)
		cout << (char) ('A'+toposort[i]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
   
    while(T--)
        solve();
}