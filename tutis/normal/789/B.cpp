#include <bits/stdc++.h>
#define INF 50e20
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int64_t b, q, l, m;
	cin >> b >> q >> l >> m;
	set<int64_t>bad;
	for (int64_t i = 0; i < m; i++)
	{
		int64_t a;
		cin >> a;
		bad.insert(a);
	}
	int64_t k = 0;
	int jau=0;
	while (abs(b) <= l and k<60 and jau<=1000)
	{
		if (bad.count(b) == 0)
			k++;
		b *= q;
		jau++;
	}
	if(k>=60)
	{
		cout<<"inf";
		return 0;
	}
	cout << k;
	return 0;
}