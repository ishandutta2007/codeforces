
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <array>
#include <chrono>
#include <unordered_set>
#include <unordered_map>

#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <cfloat>
#include <deque>
#include <bitset>
#include <numeric>
#include <string>
#include <tuple>
#include <valarray>

#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define all(e) (e).begin(), (e).end()
#define rep(a,b,c) for(int a = b; a < c; ++a)
#define ll long long
#define pb push_back
using namespace std;


void run_case(int casenum)
{
	int n, g, b;
	cin >> n >> g >> b;

	ll lb = 1, rb = 1e18;

	while(lb < rb) {
		ll md = (lb + rb) / 2;
		ll x = md;
		ll loops = 1LL * g * (x / (g + b));
		ll extras = 1LL * b * (x / (g + b));
		x %= (g + b);
		// cout << x << "\n";
		loops += min(1LL*g, x);
		extras += max(0LL, x-g);

		if(loops >= (n + 1) / 2 && loops + extras >= n) {
			rb = md;
		} else {
			lb = md + 1;
		}
	}

	cout << lb << "\n";


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;

	int numcase = 1;
	while(T--)
		run_case(numcase++);
}