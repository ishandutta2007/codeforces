#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200100;
const int lMAX = 2000100;
const ll MAX = 4000000000000000000ll;

struct point
{
	ll t, x, y, r, mod, orz[2];
};

point p[N];
bool test;
ll n, l;
vector <int> ans, ans1, ans2;

bool compare(point a, point b)
{
	return a.mod < b.mod;
}

ll floor (ll a, ll b)
{
	ll ans = 0;
	if (a > 0 ^ b > 0 && a % b)
		ans = -1;
	ans += a / b;
	return ans;
}

ll ceil (ll a, ll b)
{
	ll ans = 0;
	if (!(a > 0 ^ b > 0) && a % b)
		ans = 1;
	ans += a / b;
	return ans;
}

vector <int> check(int type)
{
	ans.clear();
	ll smax = MAX, smin = -MAX;
	for (int i = 0; i <= n; i++)
	{
		ll dr = p[i + 1].r - p[i].r, dmod = p[i + 1].mod - p[i].mod, dx = p[i + 1].orz[type] - p[i].orz[type];
		if (!dr)
		{
			if (dmod < dx)
			{
				printf("NO");
				exit(0);
			}	
			continue;
		}
		if (dr > 0)
		{
			smax = min(smax, floor(dx, dr));
			smin = max(smin, ceil(dx - dmod, dr));
		}
		else
		{
			smax = min(smax, floor(dx - dmod, dr));
			smin = max(smin, ceil(dx, dr));
		}
		if (smax < smin)
		{
			printf("NO");
			exit(0);
		}
	}
	int j = 0;
	for (int i = 0; i <= n + 1; i++)
	{
		while (j < p[i].orz[type] - smin * p[i].r)
		{
			ans.push_back(1);
			j++;
		}
		while (ans.size() < p[i].mod)
			ans.push_back(0);
	}
	return ans;
}
int main()
{
	scanf("%I64d%I64d", &n, &l);
	p[0].t = p[0].x = p[0].y = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d%I64d", &p[i].t, &p[i].x, &p[i].y);
		if (p[i].x + p[i].y + p[i].t & 1)
			return printf("NO"), 0;
		p[i].r = p[i].t / l;
		p[i].mod = p[i].t % l;
		p[i].orz[0] = p[i].x + p[i].y + p[i].t >> 1;
		p[i].orz[1] = p[i].x - p[i].y + p[i].t >> 1;
	}
	p[n + 1].mod = l;
	p[n + 1].r = -1;
	test = (n == 1000 && p[2].t == 10011);
	sort(p, p + n + 2, compare);
	ans1 = check(0);
	ans2 = check(1);
	for (int i = 0; i < ans1.size(); i++)
		putchar("LDUR"[2 * ans1[i] + ans2[i]]);
	putchar('\n');
	return 0; 
}