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
int m;

char w[1000001];
int x[1001001];


int main () {
	gets (w);	
	n = strlen (w);
	for (int i = 0; i < n; i++) x[i] = w[n - i - 1] - '0';
	int j = 0, ans = 0;
	while (j + 1 < n)
		if (x[j] == 1) {
			int k = j;
			while (x[k] == 1) {
				x[k] = 0;
				k++;
			}
			if (k + 1 > n) n = k + 1;
			x[k] = 1;
			ans++;
		} else { j++; ans++; }
	printf ("%d\n", ans);
	return 0;
}