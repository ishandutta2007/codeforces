#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

const int N = 110;
const int ALP = 'z' - 'a' + 1;
int n;
vector<string> gens;
bool used[ALP];
int max_pos[ALP];

void solve()
{
	int n;
	cin >> n;
	gens.resize(n);
	for (auto& gen : gens)
	{
		cin >> gen;
		for (auto& c : gen)
			c -= 'a';
	}
	string ans = "";
	while (gens.size())
	{
		fill(max_pos, max_pos + ALP, -1);
		for (auto gen : gens)
			for (int i = 0; i < gen.size(); ++i)
				max_pos[gen[i]] = max(max_pos[gen[i]], i);
		int begin = -1;
		for (int i = 0; i < ALP; ++i)
			if (max_pos[i] >= 0 && (begin == -1 || max_pos[i] < max_pos[begin] || 
				(max_pos[i] == max_pos[begin] && used[i])))
				begin = i;
		for (int i = 0; i < gens.size(); ++i)
			if (gens[i][0] == begin)
			{
				for(auto c : gens[i])
					if (!used[c])
					{
						used[c] = true;
						ans += c;
					}
				gens.erase(gens.begin() + i);
				break;
			}
	}
	for (auto& c : ans)
		c += 'a';
	cout << ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}