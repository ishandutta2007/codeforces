#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = 1337;
const int N = 200200;
const int A = 26;
map<string, vector<string>> mapchik;
int go[N][A];
vector<int> inTrie[N];
vector<int> myV[N];
int k;

int calcInV(int v, int l, int r) {
	return lower_bound(all(inTrie[v]), r) - lower_bound(all(inTrie[v]), l);
}

ll solve(vector<string> a) {
	sort(all(a));
	int n = (int)a.size();
	int m = (int)a[0].size();
	while(k > 0) {
		k--;
		for (int c = 0; c < A; c++)
			go[k][c] = 0;
		inTrie[k].clear();
	}
	k++;
	for (int i = 0; i < n; i++) {
		myV[i] = vector<int>(m + 1, 0);
		int v = 0;
		inTrie[v].push_back(i);
		for (int j = m - 1; j >= 0; j--) {
			int c = (int)(a[i][j] - 'a');
			if (go[v][c] == 0) go[v][c] = k++;
			v = go[v][c];
			inTrie[v].push_back(i);
			myV[i][j] = v;
		}
	}
	ll ans = (ll)n * (n - 1);
	int l = 0;
	while(l < n) {
		int r = l;
		while(r < n && a[l] == a[r]) r++;
		ans -= (ll)(r - l) * (r - l - 1) / 2;
		l = r;
	}
	vector<pii> st;
	st.push_back(mp(n, -1));
	for (int i = n - 2; i >= 0; i--) {
		int lcp = 0;
		while(lcp < m && a[i][lcp] == a[i + 1][lcp]) lcp++;
		while(st.back().second >= lcp) st.pop_back();
		st.push_back(mp(i + 1, lcp));
		vector<int> notSorted;
		for (int j = 1; j < m; j++)
			if (a[i][j] < a[i][j - 1])
				notSorted.push_back(j);
		notSorted.push_back(m);
		for (int j = 1; j < (int)st.size(); j++) {
			int l = st[j].first, r = st[j - 1].first;
			int lcp = st[j].second;
			if (lcp < m)
				lcp = *upper_bound(all(notSorted), lcp);
			ans -= calcInV(myV[i][lcp], l, r);
		}
	}
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s, p;
	while(n--) {
		cin >> s;
		p = s;
		sort(all(p));
		mapchik[p].push_back(s);
	}
	n = 0;
	ll ans = 0;
	for (auto t : mapchik) {
		ans += solve(t.second);
		ans += INF * n * (int)t.second.size();
		n += (int)t.second.size();
	}
	cout << ans << endl;

	return 0;
}