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
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

map<string, int> a;
set<string> all;

void solve(string s) {
    int p = 0;
    while(p < (int)s.length() && s[p] != '?') p++;
    if (p == (int)s.length()) {
        all.insert(s);
        return;
    }
    for (char c = 'a'; c <= 'e'; c++) {
        s[p] = c;
        solve(s);
    }
    solve(s.substr(0, p) + s.substr(p + 1));
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s;
    while(n--) {
        cin >> s;
        a[s]++;
    }
    while(m--) {
        cin >> s;
        all.clear();
        solve(s);
		int ans = 0;
		for (string p : all)
			if (a.count(p) > 0)
				ans += a[p];
        cout << ans << "\n";
    }
    
    return 0;
}