#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FileName = "input";

const int MAXN = 3e5 + 100;

int n, k, b, c;
vector <int> arr;
vector <int> event[5];
long long sum, mod, ans = 1e18;
multiset <long long> que;

long long f(long long s, long long t) {
	return ((t - s) / 5) * b + ((t - s) % 5) * c;
}

int main(int argc, char const *argv[]) {
    srand(time(0));
    //read(FileName);
    ios::sync_with_stdio(0);
    cin >> n >> k >> b >> c;
    arr.resize(n);
    b = min(b, c * 5);
    for (int i = 0; i < n; ++i) {
    	cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < 5; ++j) {
    		event[(((arr[i] + j) % 5) + 5) % 5].pb(arr[i] + j);
    	}
    }
    for (int j = 0; j < 5; ++j) {
    	int L = 0;
    	sum = 0, mod = 0;
    	que.clear();
    	for (int i = 0; i < n; ++i) {
    		while (L < n && arr[L] <= event[j][i]) {
    			que.insert(-f(arr[L], event[j][i]) - mod);
    			sum += f(arr[L], event[j][i]);
    			++L;
    		}
    		while (que.size() > k) {
    			sum += *que.begin() + mod;
    			que.erase(que.begin());
    		}
    		if (que.size() == k) {
    			// if (sum < ans) {
    			// 	cout << sum << ' ' << event[j][i] << endl;
    			// }
    			ans = min(ans, sum);
    		}
    		if (i != n - 1) {
    			assert(event[j][i] <= event[j][i + 1]);
    			mod -= f(event[j][i], event[j][i + 1]);
    			sum += f(event[j][i], event[j][i + 1]) * que.size();
    		}
    	}
    }
    cout << ans << endl;
}