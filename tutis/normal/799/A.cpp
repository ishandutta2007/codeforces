#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int time = 0;
	int keks = 0;
	while (keks < n)
	{
		time += t;
		keks += k;
	}
	int time2 = time - 1;
	int keks2 = (time2 - d) / t + time2 / t;
	keks2 *= k;
	if (keks2 >= n)
		cout << "YES";
	else
		cout << "NO";

}