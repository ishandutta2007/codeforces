/*input
7
4 3 5 1 2 2 1
*/
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
bool blogai(deque<int> &i)
{
	if (i.size() <= 1)
		return false;
	if (i[i.size() - 2] < i.back() - 1)
		return true;
	if (i.size() <= 2)
		return false;
	if (i.back() != i[i.size() - 2] && i[i.size() - 2] != i[i.size() - 3])
		return true;
	if (i[0] != i[1] && i[1] != i[2])
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
		cin >> i;
	sort(a, a + n);
	deque<int>v, ans;
	int maxi = 0;
	int R = -1;
	for (int r : a)
	{
		v.push_back(r);
		while (blogai(v))
			v.pop_front();
		if (v.size() > maxi)
		{
			maxi = v.size();
			R = r;
		}
	}
	for (int r : a)
	{
		if (r > R)
			break;
		ans.push_back(r);
		while (blogai(ans))
			ans.pop_front();
	}
	cout << ans.size() << "\n";
	int w = -100;
	for (auto it = ans.begin(); it != ans.end();)
	{
		if ((*it > w))
		{
			w = *it;
			cout << w << " ";
			it++;
		}
		else
		{
			it++;
		}
	}
	reverse(ans.begin(), ans.end());
	int j = -1;
	for (int i : ans)
	{
		if (j == i)
			cout << i << ' ';
		j = i;
	}
}