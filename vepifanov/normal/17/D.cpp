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
int m, c;

char sn[2000000], sb[2000000];

int main() {
	scanf ("%s%s%d", sb, sn, &c);
	int b = 0;
	for (int i = 0; sb[i]; i++) b = ((long long)b * 10 + sb[i] - '0') % c;
	int len = strlen (sn);
	int R = 1, cur = b, ans = 1;
	for (int i = len - 1; i >= 0; i--) {
		sn[i] -= R;
		R = 0;
		if (sn[i] < '0') { sn[i] += 10; R = 1; }
		for (int j = 0; j < sn[i] - '0'; j++) ans = ((long long)ans * cur) % c;
		int ncur = 1;
		for (int j = 0; j < 10; j++) ncur = ((long long)ncur * cur) % c;
		cur = ncur;
	}
	ans = ((long long)ans * (b + c - 1)) % c;
	if (ans == 0) ans = c;
	printf ("%d\n", ans);
	return 0;
}