#include <iostream>
#include <algorithm>
 
using namespace std;
 
int n;
int sum;
int l, r;
int ans = 360;
int a[360];
 
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (r < n)
	{
		sum += a[r];
		while (sum >= 180)
		{
			ans = min(ans, 2 * abs(180 - sum));
			sum -= a[l];
			l++;
		}
		ans = min(ans, 2 * abs(180 - sum));
		r++;
	}
	cout << ans << endl;
}