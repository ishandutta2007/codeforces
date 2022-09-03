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
int cnt[256];
char a[300], b[300];

int main() {
	gets (a);
	gets (b);
	for (int i = 0; a[i]; i++) cnt[a[i]]++;
	for (int i = 0; b[i]; i++) {
		if (b[i] == ' ') continue;
		cnt[b[i]]--;
		if (cnt[b[i]] < 0) { printf ("NO\n"); re 0; }
	}
	printf ("YES\n");
	return 0;
}