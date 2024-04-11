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
int m, last;
char w[100000], ww[100000];
int a[100000], b[100000], dd[100000], prev[100000];
vector<pair<int, int> > v;

int check (int x) {
	if (last == -1) return 0;
	for (int i = x; i >= last; i--) 
		if (dd[i] < 2)
			return 0;
	for (int i = last; i <= x; i++) dd[i] -= 2;
	ww[last] = ')';
	ww[x + 1] = '(';
	last--;
	while (last >= 0 && (w[last] != '?' || ww[last] == ')')) last--;
	return 1;
}
                         
int go (int a, int b) {
	int d = 0;
	for (int i = 0; i < n; i++) {
		char c = w[i];
		if (c == '?')
			if (a > 0) { last = i; c = '('; a--; } else { c = ')'; b--; }
		d += int (c == '(') - int (c == ')');
		if (d < 0) return 1;
		ww[i] = c;
		dd[i] = d;
	}
	if (d != 0) return 1;
	return 0;
}
                 
int main() {
	gets (w);
	n = strlen (w);
	int d = 0, m = 0;
	for (int i = 0; i < n; i++)
		if (w[i] == '?') {
			m++;
			scanf ("%d%d", &a[i], &b[i]);
			v.push_back (make_pair (a[i] - b[i], i));
		} else d += int (w[i] == '(') - int (w[i] == ')');
	int A = (m - d) / 2, B = (m + d) / 2;
	if ((m + d) % 2 || A < 0 || B < 0) {
		printf ("-1\n");
		return 0;
	}
       	sort (v.begin (), v.end ());
       	last = -1;
       	if (go (A, B)) {
       		printf ("-1\n");
       		return 0;
       	}
	long long ans = 0;
	for (int i = 0; i < v.size (); i++) {
		int j = v[i].second;
//		printf ("%s %s %d %I64d\n", ww, w, last, ans);
		if (ww[j] == '(') {
			ans += a[j]; 
			w[j] = '(';
			if (last == j) {
				last--;
				while (last >= 0 && (w[last] != '?' || ww[last] == ')')) last--;
			}
		} else
		if (ww[j] == ')') {
			if (check (j - 1)) {
				ans += a[j]; 
				w[j] = '(';
			} else {
				ans += b[j];
				w[j] = ')';
			}
		} 
	}
       	if (go (0, 0)) {
       		printf ("-1\n");
       		return 0;
       	}
	printf ("%I64d\n%s\n", ans, w);
	return 0;
}