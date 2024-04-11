#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define mp make_pair

const int N = 300300;
int ans;
int n;
pll a[N];
set<pli> s1, s2;
ll w, S;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ans = n;
	ll _w;
	scanf("%lld%lld", &S, &_w);
	n--;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a[i].first, &a[i].second);
		a[i].second = a[i].second - a[i].first + 1;
	}
	sort(a, a + n);
	reverse(a, a + n);
	a[n++] = mp(0, S + 1);
	w = 0;
	for (int i = 0; i < n; i++)
	{
	//	s1.insert(mp(a[i].second, i));
		if (a[i].first > S)
		{
			s1.insert(mp(a[i].second, i));
			continue;
		}
		if (!s2.empty())
		{
			pli tmp = *s2.begin();
			s2.erase(s2.begin());
			w += tmp.first;
			s1.insert(mp(-tmp.first, tmp.second));
		}
		while(!s1.empty())
		{
			pli t = *s1.begin();
			if (w + t.first > S - a[i].first) break;
			s1.erase(s1.begin());
			s2.insert(mp(-t.first, t.second));
			w += t.first;
		}
		ans = min(ans, i - (int)s2.size());
		s1.insert(mp(a[i].second, i));
	}
	printf("%d\n", ans + 1);

	return 0;
}