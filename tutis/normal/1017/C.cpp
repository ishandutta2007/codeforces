/*input
101
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>answer(vector<int>y)
{
	int n = y.size();
	if (n <= 0)
		return {};
	if (n == 1)
		return {y[0]};
	if (n == 2)
		return {y[0], y[1]};
	vector<int>a;
	vector<int>b;
	for (int i = 1; i + 1 < y.size(); i++)
		if (i % 2 == 0)
			a.push_back(y[i]);
		else
			b.push_back(y[i]);
	vector<int>ans = answer(a);
	ans.push_back(y.front());
	ans.push_back(y.back());
	for (int i : answer(b))
		ans.push_back(i);
	return ans;
}
vector<int>answer1(vector<int>y)
{
	int n = y.size();
	pair<int, int>gers = {2 * n + 10, 2 * n + 10};
	for (int a = 1; a <= n; a++)
	{
		int c = n / a;
		if (n % a != 0)
			c++;
		gers = min(gers, {a + c, a});
	}
	int a = gers.second;
	vector<int>ans = y;
	for (int i = 0; i * a < n; i++)
	{
		if (i * a + a < n)
			reverse(ans.begin() + i * a, ans.begin() + i * a + a);
		else
			reverse(ans.begin() + i * a, ans.end());
	}
	return ans;
}
int kiek(vector<int> &c)
{
	int n = c.size();
	int inc[n + 1];
	int dec[n + 1];
	fill_n(inc, n + 1, 0);
	fill_n(dec, n + 1, 0);
	int a = 0;
	int b = 0;
	for (int i : c)
	{
		inc[i] = 1;
		dec[i] = 1;
		for (int j = i + 1; j <= n; j++)
			dec[i] = max(dec[i], 1 + dec[j]);
		for (int j = i - 1; j > 0; j--)
			inc[i] = max(inc[i], 1 + inc[j]);
		a = max(a, inc[i]);
		b = max(b, dec[i]);
	}
	return a + b;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>y;
	for (int i = 1; i <= n; i++)
		y.push_back(i);
	for (int i : answer1(y))
		cout << i << " ";
}