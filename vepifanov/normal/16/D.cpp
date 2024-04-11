#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
char w[100];

int main() {
	scanf ("%d\n", &n);
	int ans = 1, last = -1, cnt = 1;
	for (int i = 0; i < n; i++) {
		gets (w);
		int cur = (((w[1] - '0') * 10 + (w[2] - '0')) % 12) * 60 + (w[4] - '0') * 10 + (w[5] - '0') + int (w[7] == 'p') * 720;
		if (cur > last) {
			cnt = 1;
		} else
		if (cur < last) {
			ans++;
			cnt = 1;
		} else  {
			cnt++;
			if (cnt > 10) { cnt -= 10; ans++; }
		}
		last = cur;
	}
	printf ("%d\n", ans);
	return 0;
}