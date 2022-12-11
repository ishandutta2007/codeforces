#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;

const int N = 1e5 + 7;

int m;
LL n, a, d, T[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> a >> d;
	for(int i = 1; i <= m; i++)
		cin >> T[i];
	sort(T + 1, T + m + 1);
	LL last = 0, ans = 0;
	for(int i = 1; i <= m; i++)
	{
		if(last >= T[i]) continue;
		LL k = min(last / a + 1, n + 1);
		LL l = min(T[i] / a, n);
		if(k <= l)
		{
			LL ile = d / a + 1;
			ans += (l - k + 1) / ile;
			k += (l - k + 1) / ile * ile;
			if(k <= l)
				ans++, last = a * k + d;
			else
				last = a * (k - ile) + d;	
		}
		if(last < T[i])
			ans++, last = T[i] + d;	
		//cout << i << " " << ans << " " << last << "\n";
	}
	LL k = last / a + 1;
	LL l = n;
	//cout << k << " " << l << "\n";
	if(k <= l)
	{
			LL ile = d / a + 1;
			ans += (l - k + 1) / ile;
			k += (l - k + 1) / ile * ile;
			if(k <= l)
				ans++, last = a * k + d;
			else
				last = a * (k - ile) + d;	
	}
	cout << ans << "\n";
	return 0;
}