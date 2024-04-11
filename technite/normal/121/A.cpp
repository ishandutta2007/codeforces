#include <bits/stdc++.h>
using namespace std;
long long l, r, sum;
set<long long> s;
 
void f(long long x)
{
	s.insert(x);
	if (x < r)
	{
		f(x * 10 + 4);
		f(x * 10 + 7);
	}
}
 
int main()
{
	cin >> l >> r;
	f(0);
	while(l <= r)
	{
		auto it = s.lower_bound(l);
		sum += (min(r, *it) - l + 1) * *it;
		l = *it + 1;
	}
	cout << sum;
}