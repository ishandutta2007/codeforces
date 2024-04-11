/*input
2
4 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
bool lucky(int n)
{
	while (n > 0)
	{
		if (n % 10 != 4 && n % 10 != 7)
			return false;
		n /= 10;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<pair<int, int>>X;
	for (int i = 0; i < n; i++)
		X.push_back({a[i], i});
	sort(X.begin(), X.end());
	int kur[n];
	int KUR[n];
	for (int i = 0; i < n; i++)
	{
		kur[X[i].second] = i;
		KUR[i] = X[i].second;
	}
	int l = -1;
	for (int i = 0; i < n; i++)
		if (lucky(a[i]))
			l = i;
	vector<pair<int, int>>ans;
	for (int c = 0; c < n; c++)
	{
		if (kur[c] == c)
			continue;
		int i = KUR[c];
		if (!lucky(a[i]) && l != -1)
		{
			int b = kur[i];
			int kl = kur[l];
			int kii = kur[b];
			if (l != b)
				ans.push_back({l, b});
			swap(a[l], a[b]);
			if (i != b)
				ans.push_back({b, i});
			swap(a[b], a[i]);
			kur[b] = b;
			KUR[b] = b;
			kur[i] = kl;
			KUR[kl] = i;
			kur[l] = kii;
			KUR[kii] = l;
			l = i;
		}
	}
	for (int c = 0; c < n; c++)
	{
		if (kur[c] == c)
			continue;
		int i = KUR[c];
		if (lucky(a[i]))
		{
			int j = kur[i];
			int k = kur[j];
			ans.push_back({i, j});
			swap(a[i], a[j]);
			kur[j] = j;
			KUR[j] = j;
			kur[i] = k;
			KUR[k] = i;
		}
	}
	if (is_sorted(a, a + n))
	{
		cout << ans.size() << "\n";
		for (auto i : ans)
			cout << i.first + 1 << " " << i.second + 1 << "\n";
		return 0;
	}
	cout << "-1\n";
}/**/