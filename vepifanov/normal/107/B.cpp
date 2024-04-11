#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m, h;
int cnt[100001];

int main () {
	scanf ("%d%d%d", &n, &m, &h);
	int sum = 0, cur = 0;
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x);
		sum += x;
		if (i == h - 1) cur = x;
	}
	if (sum < n) printf ("-1\n"); else 
	if (sum - cur < n - 1) printf ("1\n"); else {
		for (int i = 1; i <= sum - 1; i++) cnt[i]++;
		for (int i = 1; i <= sum - cur - n + 1; i++) cnt[i]++;
		for (int i = 1; i <= sum - cur; i++) cnt[i]--;
		for (int i = 1; i <= sum - n; i++) cnt[i]--;
		double res = 1;
		for (int i = 1; i <= sum; i++) {
			for (int j = 0; j < cnt[i]; j++) res /= i;
			for (int j = 0; j > cnt[i]; j--) res *= i;
		}	
		printf ("%.10f\n", 1 - res);
	}	
	return 0;
}