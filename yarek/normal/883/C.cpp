#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;

LL f, T, t0;
LL a[2], t[2], p[2];

int main()
{
	cin >> f >> T >> t0;
	for(int i = 0; i < 2; i++)
		cin >> a[i] >> t[i] >> p[i];
	LL ans = 1e18 + 7;
	for(int i = 0; i < 1; i++)
	{
		for(LL j = 0; j <= f; j++)
		{
			LL cena = p[i] * ceil(LD(j) / LD(a[i])), pozostale = T - j * t[i];
			if(pozostale < 0) continue;
			if((f - j) * t0 <= pozostale) ans = min(ans, cena);
			//cout << f << " " << l << " " << cena << " " << pozostale << "\n";
			if(t[i ^ 1] >= t0) continue;
			LL l = ceil(LD(pozostale - (f - j) * t0) / LD(-t0 + t[i ^ 1]));
			//cout << j << " " << l << " " << cena << " " << pozostale << "\n";
			if(l < 0) continue;
			cena += p[i ^ 1] * ceil(LD(l) / LD(a[i ^ 1]));
			//cout << j << " " << l << " " << cena << " " << pozostale << "\n";
			if(l + j <= f && l * t[i ^ 1] + t0 * (f - j - l) <= pozostale)
				ans = min(ans, cena);
		}
	}	
	if(ans == 1e18 + 7) ans = -1;
	cout << ans << "\n";
	return 0;
}