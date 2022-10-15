/***
4
22 73 9
45 64 6
47 55 7
2 62 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, int>F_;
int F(int n)
{
	if (F_.count(n))
		return F_[n];
	if (n == 0)
		return F_[n] = 1;
	if (n < 10)
		return F_[n] = n;
	int ans = 1;
	while (n > 0)
	{
		if (n % 10 != 0)
			ans *= (n % 10);
		n /= 10;
	}
	return F_[n] = F(ans);
}
int S[1000001][10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 1000001; i++)
	{
		S[i][F(i)]++;
	}
	for (int i = 1; i < 1000001; i++)
	{
		for (int k = 0; k < 10; k++)
			S[i][k] += S[i - 1][k];
	}
	int Q;
	cin >> Q;
	while (Q--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << S[r][k] - S[l - 1][k] << endl;
	}
}