#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int n, m, k;
char disc[128][64];
int t[128];
char ss[128];
bool busy[50000];

int get_time (char * s) {
	return ((s[0]-'0')*10 + s[1]-'0') * 60 + ((s[3]-'0')*10 + s[4]-'0');
}

pair <pii, pii> a[128];
int d[24*60*30 + 12][128];
int fromi[24*60*30 + 12][128];
int fromj[24*60*30 + 12][128];
bool take[24*60*30 + 12][128];
int end[128][24*60*30+12];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	scanf ("%d%d%d", &n, &m, &k);
	REP (i, n) 
		scanf ("%s", disc[i]);
	REP (i, n)
		scanf ("%d", t + i);

	REP (t, 4) {
		scanf ("%s", ss);
		int from = get_time (ss);
		int to = get_time (ss + 6);
		REP (day, k) 
			FOR (x, from, to + 1)
				busy[day * 24*60 + x] = true;
	}
	int T = 24*60*k;
	CL (end, -1);
	REP (i, n) {
		int u = 0;
		int x = t[i];
		while (u < T) {
			if (!busy[u]) {
				--x;
				if (!x)
					break;
			}
			++u;
		}
		if (x) continue;
		end[i][0] = u;
		REP (j, T-1) {
			if (!busy[j]) {
				++u;
				while (u < T && busy[u]) ++u;
			}
			if (u >= T) break;
			end[i][j+1] = u;
		}
	}
	REP (i, m) {
		scanf ("%s", ss);
		a[i].Y.X = -1;
		a[i].X.Y = i;
		REP (j, n)
			if (!strcmp (ss, disc[j])) {
				a[i].Y.X = j;
				break;
			}
		int day;
		scanf ("%d", &day);
		day--;
		scanf ("%s", ss);
		a[i].X.X = get_time (ss);
		a[i].X.X += day * 24*60;

		scanf ("%d", &a[i].Y.Y);
	}
	sort (a, a + m);
	CL (d, -1);
	d[0][0] = 0;
	REP (i, T+1) {
		REP (j, m+1) {
			if (d[i+1][j] < d[i][j]) {
				d[i+1][j] = d[i][j];
				fromi[i+1][j] = i;
				fromj[i+1][j] = j;
				take[i+1][j] = false;
			}
			if (j < m && d[i][j+1] < d[i][j]) {
				d[i][j+1] = d[i][j];
				fromi[i][j+1] = i;
				fromj[i][j+1] = j;
				take[i][j+1] = false;
			}
			if (j < m && a[j].Y.X != -1) {
				if (end[a[j].Y.X][i] != -1 && !busy[i]) {
					int t = end[a[j].Y.X][i]+1;
					if (t <= a[j].X.X && d[t][j+1] < d[i][j] + a[j].Y.Y) {
						d[t][j+1] = d[i][j] + a[j].Y.Y;
						fromi[t][j+1] = i;
						fromj[t][j+1] = j;
						take[t][j+1] = true;
					}
				}
			}
		}
	}
	int x = T;
	int y = m;
	cout << d[x][y] << endl;
	vector <string> ans;
	while (x || y) {
		int tx = x, ty = y;
		x = fromi[tx][ty];
		y = fromj[tx][ty];
		if (take[tx][ty]) {
			ostringstream str;
			str << a[y].X.Y+1 << ' ';

			str << (x/(24*60)+1) << ' ';
			str.fill('0');
			str.width(2);
			str << (x%(24*60))/60;
			str << ':';
			str.fill('0');
			str.width(2);
			str << (x%(24*60))%60 << ' ';

			tx--;

			str << (tx/(24*60)+1) << ' ';
			str.fill('0');
			str.width(2);
			str << (tx%(24*60))/60;
			str << ':';
			str.fill('0');
			str.width(2);
			str << (tx%(24*60))%60;

			ans.pb (str.str());
		}			
	}
	reverse (all (ans));
	cout << sz (ans) << endl;
	REP (i, sz (ans))
		cout << ans[i] << endl;
	return 0;
}