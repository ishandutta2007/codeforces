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
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

const int N = 500100;
const int M = 50;
const double eps = 1e-10;

int n;
int m;

int h[N];
double sum[N];
double mult[N];
vi v[N];
int x[N];
int y[N];
int t[N];
int p[N];
double res[N][M];
double old[N][M];

int main () {
	scanf ("%d", &n);
	m = 1;
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &t[i], &x[i]); x[i]--;
		if (t[i] == 1) y[i] = m++;
	}
	res[0][0] = 1;
	for (int i = 0; i < n; i++)
		if (t[i] == 1) {
			p[y[i]] = x[i];
			int a = y[i];
			res[a][0] = 1;
			for (int it = 0; it + 1 < M && a != 0; it++) {
				int b = p[a];
				double sc = 0, sy = 0;
				for (int j = 0; j < M; j++) old[b][j] = res[b][j];
				if (it > 0) {
					res[b][0] = res[b][0] * 2;
					sc = res[b][0];
					sy = 0.5;
					double tmp = sc * sy;
					for (int j = 1; j < it + 2; j++) {
						sy += old[a][j - 1] * 0.5;
						res[b][j] = (res[b][j] + tmp - sc * sy) / sy;
						sc += res[b][j];
						tmp = sc * sy;
					}
				}
				sc = sy = 0;
				sc = res[b][0];
				sy = 0.5;
				res[b][0] = res[b][0] * 0.5;
				double tmp = sc * sy;
				for (int j = 1; j < it + 2; j++) {
					sc += res[b][j];
					sy += res[a][j - 1] / 2;
					double mul = sc * sy;
					res[b][j] = mul - tmp;
					tmp = mul;
				}
				a = b;
				if (abs (res[a][it] - old[a][it]) < eps) break;
			}
		} else {
			double ans = 0;
			for (int j = 1; j < M; j++)
				ans += res[x[i]][j] * j;
			printf ("%.10f\n", ans);
		}
	cerr << clock () << endl;	
	return 0;
}