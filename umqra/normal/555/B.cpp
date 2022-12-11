#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e5 + 10;
const int E = 4 * N;

struct Event
{
	int t;
	ll c;
	int ind;
	Event () : t(), c(), ind() {}
	Event (int _t, ll _c, int _ind) : t(_t), c(_c), ind(_ind) {}
};

int answer[N];
Event listE[E];
ll bL[N], bR[N];
set <pii> setP;
int indE = 0;

bool cmp(const Event &a, const Event &b)
{
	if (a.c != b.c)
		return a.c < b.c;
	return a.t > b.t;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &bL[i], &bR[i]);
	}
	for (int i = 0; i < n - 1; i++)
	{
		listE[indE++] = Event(-1, bR[i + 1] - bL[i], i);
		listE[indE++] = Event(1, bL[i + 1] - bR[i], i);
	}
	for (int i = 0; i < m; i++)
	{
		ll x;
		scanf("%lld", &x);
		listE[indE++] = Event(0, x, i);
	}
	memset(answer, -1, sizeof(answer));
	sort(listE, listE + indE, cmp);
	for (int i = 0; i < indE; i++)
	{
		auto e = listE[i];
		if (e.t == 1)
		{
			setP.insert(mp(bR[e.ind + 1] - bL[e.ind], e.ind));
		}
		else if (e.t == -1)
			setP.erase(mp(bR[e.ind + 1] - bL[e.ind], e.ind));
		else
		{
			if (setP.size() > 0)
			{
				auto p = *setP.begin();
				setP.erase(p);
				answer[p.Y] = e.ind;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
		if (answer[i] == -1)
		{
			puts("No");
			return 0;
		}

	puts("Yes");
	for (int i = 0; i < n - 1; i++)
		printf("%d ", answer[i] + 1);
	return 0;
}