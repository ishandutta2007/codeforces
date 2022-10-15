/***
2
0 40 100 100
60 0 40 40
0 60 0 45
0 60 55 0
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld A[65][65];
struct tree
{
	ld pre[65];
	ld P[65];
	tree *left = NULL;
	tree *right = NULL;
	void init(ll a, ll b, ld cost)
	{
		if (a < b)
		{
			left = new tree;
			right = new tree;
			left->init(a, (a + b) / 2, cost / 2.0);
			right->init((a + b) / 2 + 1, b, cost / 2.0);
			for (ll i = a; i <= b; i++)
			{
				P[i] = 0;
				pre[i] = 0;
				pre[i] = 0;
			}
			for (ll i = a; i <= (a + b) / 2; i++)
			{
				for (ll j = (a + b) / 2 + 1; j <= b; j++)
				{
					P[i] += (left->P[i] * right->P[j]) * A[i][j];
					P[j] += (left->P[i] * right->P[j]) * A[j][i];
				}
			}
			for (ll i = a; i <= (a + b) / 2; i++)
			{
				for (ll j = (a + b) / 2 + 1; j <= b; j++)
				{
					pre[i] = max(pre[i], (left->pre[i] + right->pre[j]) + cost * P[i]);
				}
			}
			for (ll j = (a + b) / 2 + 1; j <= b; j++)
			{
				for (ll i = a; i <= (a + b) / 2; i++)
					pre[j] = max(pre[j], (left->pre[i] + right->pre[j]) + cost * P[j]);
			}
		}
		else
		{
			fill_n(pre, 65, 0);
			fill_n(P, 65, 1);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll N;
	cin >> N;
	ll sz = (1 << N);
	for (ll a = 1; a <= sz; a++)
		for (ll b = 1; b <= sz; b++)
		{
			cin >> A[a][b];
			A[a][b] /= 100.0;
		}
	tree *x = new tree;
	x->init(1, sz, sz / 2);
	ld ans = 0;
	for (ll i = 1; i <= sz; i++)
	{
		ans = max(ans, x->pre[i]);
	}
	cout << fixed << setprecision(19) << ans << "\n";
}