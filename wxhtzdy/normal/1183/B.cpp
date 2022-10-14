#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>
#define f first
#define s second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n, k;
		cin >> n >> k;
		int niz[n];
		for(int i = 0; i < n; i++)
			cin >> niz[i];
		int mx = INT_MAX;
		int mn = 0;
		for(int i = 0; i < n; i++)
		{
			mx = min(mx, niz[i]+k);
			mn = max(mn, max(1, niz[i]-k));
		}
		if(mn > mx) cout << -1 << "\n";
		else cout << mx << "\n";
	}
	return 0;
}