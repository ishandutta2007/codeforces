/*input
3
1 2 3
2
1 2
2 3
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int a[1600];
struct BIT
{
	int A[1501];
	void reset()
	{
		for (int i = 1; i <= 1500; i++)
			A[i] = 0;
	}
	BIT()
	{
		for (int i = 1; i <= 1500; i++)
			A[i] = 0;
	}
	void add(int i)
	{
		for (; i <= 1500; i += (i) & (-i))
			A[i]++;
	}
	int get(int i)
	{
		int ans = 0;
		for (; i > 0; i -= (i) & (-i))
			ans += A[i];
		return ans;
	}
	int get(int l, int r)
	{
		return get(r) - get(l - 1);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] < a[j])
			{
				ans++;
			}
		}
	}
	BIT X;
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		ans += (r - l + 1) * (r - l) / 2;
		ans %= 2;
		cout << (ans % 2 == 0 ? "even\n" : "odd\n");
	}
}