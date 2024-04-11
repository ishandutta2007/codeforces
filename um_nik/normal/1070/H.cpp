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
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<string, pair<int, string>> mapchik;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		set<string> setik;
		int L = s.length();
		for (int i = 0; i < L; i++)
			for (int j = i + 1; j <= L; j++)
				setik.insert(s.substr(i, j - i));
		for (string p : setik) {
			if (mapchik.count(p) == 0)
				mapchik[p] = mp(1, s);
			else
				mapchik[p].first++;
		}
	}
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		if (mapchik.count(s) == 0)
			cout << "0 -\n";
		else
			cout << mapchik[s].first << " " << mapchik[s].second << "\n";
	}

	return 0;
}