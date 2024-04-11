#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int maxn = 1005;

const int maxm = 30005;
const ll inf = 2e13;

int n;
int m;
bool was[maxn];
int c[maxm];
vector<ii> gr[maxn];
pair<ll, int> curans;
int d[maxn];
bool found;
vi edges;
int REMOVE;
int s, t;

bool go(int cur, int target, int pr)
{
	if (was[cur]) return false;
	was[cur] = true;
	if (cur == target)
	{
		found = true;
		return true;
	}
	bool ans = false;
	for (auto e : gr[cur]) if (e.fi != pr)
	{
		auto t = go(e.fi, target, cur);
		if (t) edges.pb(e.se);
		ans |= t;
	}
	return ans;
}

pair<bool, int> go2(int cur, int target, int pr, int curd, int last)
{
	//cout << "go2 " << cur << endl;
	was[cur] = true;
	d[cur] = curd;
	bool ans = false;
	if (cur == target)
	{
		found = true;
		ans = true;
	}
	int up = curd;
	for (auto e : gr[cur]) if (e.se != last && e.se != REMOVE)
	{
		if (was[e.fi])
		{
			//cout << "upd " << up << ' ' << e.fi << ' ' << e.se << ' ' << last << endl;
			up = min(up, d[e.fi]);
			continue;
		} else
		{
			//cout << "go2 to " << e.fi << ' ' << e.se << endl;
			auto t = go2(e.fi, target, cur, curd + 1, e.se);
			up = min(up, t.se);
			ans |= t.fi;
		}
	}
	//cout << "go2 " << cur << ' ' << ans << ' ' << curd << ' ' << up << endl;
	if (ans && up >= curd && cur != s)
	{
		//cout << "here" << endl;
		//cout << c[last] << ' ' << last << endl;
		curans = min(curans, {c[last], last});
	}
	return {ans, up};
}

int main () {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	s--, t--;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d%d", &a, &b, &c[i]);
		a--, b--;
		gr[a].pb({b, i});
		gr[b].pb({a, i});
	}
	found = false;
	go(s, t, -1);
	if (!found)
	{
		printf("0\n0\n");
		return 0;
	}
	pair<ll, int> answer1 = {inf, -1};
	pair<ll, ii> answer2 = {inf, {-1, -1}};
	for (auto e : edges)
	{
		REMOVE = e;
		//cout << "try " << e << endl;
		curans = {inf, m};
		found = false;
		memset(was, 0, sizeof was);
		go2(s, t, -1, 0, m);
		//cout << found << ' ' << curans.fi << ' ' << curans.se << endl;
		if (!found) answer1 = min(answer1, {c[e], e});
		else if (curans.se != m) answer2 = min(answer2, {(ll)c[e] + curans.fi, {e, curans.se}} );
	}
	if (answer1.fi >= inf && answer2.fi >= inf)
	{
		printf("-1\n");
		return 0;
	}
	if (answer1.fi < answer2.fi)
	{
		printf("%lld\n", answer1.fi);
		printf("1\n%d\n", answer1.se + 1);
	} else
	{
		printf("%lld\n", answer2.fi);
		printf("2\n%d %d\n", answer2.se.fi + 1, answer2.se.se + 1);
	}
	return 0;
}