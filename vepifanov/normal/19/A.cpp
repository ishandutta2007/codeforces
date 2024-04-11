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
string w[50];
char s[10000];
int p[50];
int res[50], qz[50], qp[50];
map<string, int> all;

bool myless (int i, int j) {
	return res[i] > res[j] || res[i] == res[j] && qz[i] - qp[i] > qz[j] - qp[j] || res[i] == res[j] && qz[i] - qp[i] == qz[j] - qp[j] && qz[i] > qz[j];
}

bool myless2 (int i, int j) {
	return w[i] < w[j];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		all[w[i]] = i;
		p[i] = i;
	}
	gets (s);
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		gets (s);
		for (int j = 0; s[j]; j++)
			if (s[j] == '-' || s[j] == ':')
				s[j] = ' ';
		stringstream in (s);
		string a, b;
		int x, y;
		in >> a >> b >> x >> y;
		int A = all[a];
		int B = all[b];
		if (x > y) res[A] += 3; else
		if (x < y) res[B] += 3; else {
			res[A]++;
			res[B]++;
		}
		qz[A] += x;
		qp[B] += x;
		qz[B] += y;
		qp[A] += y;
	}
	sort (p, p + n, myless);
	sort (p, p + n / 2, myless2);
	for (int i = 0; i * 2 < n; i++) cout << w[p[i]] << endl;
	return 0;
}