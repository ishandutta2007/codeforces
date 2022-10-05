#include <bits/stdc++.h>
using namespace std;

const int Maxn = 800005;
int n, shift, x[Maxn], y[Maxn], ord[Maxn];
multiset <int> Mu1, Mu2;
long long ans;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]), ord[i] = i, x[i] = x[i] + y[i], y[i] = x[i] - 2 * y[i];
	sort(ord + 1, ord + 1 + n, [](int a, int b){return x[a] < x[b];});
	Mu1.insert(y[ord[1]]);
	Mu2.insert(y[ord[1]]);
	for (int i = 2; i <= n; i++)
	{
		int d = x[ord[i]] - x[ord[i - 1]];
		shift += d;
		int pos1 = *Mu1.rbegin() - shift, pos2 = *Mu2.begin() + shift;
		if (y[ord[i]] < pos1)
		{
			ans += pos1 - y[ord[i]];
			Mu2.insert(*Mu1.rbegin() - 2 * shift);
			Mu1.erase(--Mu1.end());
			Mu1.insert(y[ord[i]] + shift);
			Mu1.insert(y[ord[i]] + shift);
		}
		else if (y[ord[i]] > pos2)
		{
			ans += y[ord[i]] - pos2;
			Mu1.insert(*Mu2.begin() + 2 * shift);
			Mu2.erase(Mu2.begin());
			Mu2.insert(y[ord[i]] - shift);
			Mu2.insert(y[ord[i]] - shift);
		}
		else
		{
			Mu1.insert(y[ord[i]] + shift);
			Mu2.insert(y[ord[i]] - shift);
		}
	}
	printf("%lld\n", ans / 2);
	return 0;
}