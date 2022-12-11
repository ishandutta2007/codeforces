#include<bits/stdc++.h>
using namespace std;
vector<long long> ans;
int ll[200000], tt[200000];
int main()
{
	int n;
	long long r, k = 0;
	scanf("%d%lld", &n, &r);
	for (int i = 0; i<n; i++) scanf("%d", ll + i);
	for (int i = 0; i<n; i++) scanf("%d", tt + i);
	long long d = 0, ct = 0;
	long long rr = 0;
	for (int i = 0; i<n; i++)
	{
		if (ll[i]>tt[i])
		{
			puts("-1");
			return 0;
		}
		long long l = ll[i], t = tt[i];
		long long dt = min(l, d);
		ct += dt;
		l -= dt;
		d -= dt;
		t -= dt;
		if (l * 2 <= t)
		{
			ct += 2 * l;
			continue;
		}
		long long nd = 0, left = 0, right = l;
		while (right >= left)
		{
			long long c = (left + right) / 2;
			long long dd = l - c, dt = c;
			if (dd>0) dt += dd * 2;
			if (dt>t)
			{
				left = c + 1;
			}
			else
			{
				right = c - 1;
				nd = c;
			}
		}
		ct += nd + 2 * (l - nd);

		long long tmp = ct - ((nd+r-1)%r+1);
		d += (r - (nd%r)) % r;
		k += (nd + r - 1) / r;
		if (ans.size() < 100000) ans.push_back(tmp);
		nd -= ((nd+r-1)%r+1);
		while (nd>0 && ans.size() < 100000)
		{
			tmp -= r;
			nd -= r;
			ans.push_back(tmp);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%lld\n", k);
	if (k <= 100000) for (long long i : ans) printf("%lld ", i);
}