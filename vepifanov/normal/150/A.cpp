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
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

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
ll x;
vector<ll> v;
int was[50000];
int res[50000];
ll last = 0;

int go (int i) {
	if (was[i]) re res[i];
	was[i] = 1;
	int ok = 0;
	for (int j = 1; j < i; j++)
		if (v[i] % v[j] == 0) {
			ok = 1;
			if (!go (j)) {
				last = v[j];
				re res[i] = 1;
			}
		}	
	re res[i] = 1 - ok;
}

int main() {
	cin >> x;
	for (int i = 1; (ll)i * i <= x; i++)
		if (x % i == 0) {
			v.pb (i);
			if (x / i != i) v.pb (x / i);
		}
	sort (all (v));
	if (go (sz (v) - 1)) printf ("%d\n%I64d\n", 1, last); else printf ("%d\n", 2);
        return 0;
}