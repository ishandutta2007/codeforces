/**
4 3
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll A, B;
	cin >> A >> B;
	if (A > B)
		swap(A, B);
	ll ans = 1;
	for (int i = 1; i <= A; i++)
		ans *= i;
	cout << ans;
}