
#include <bits/stdc++.h>
using namespace std;
 
int cnt;
long long ans, maxi;
string str;
int main()
{
	cin >> str;
	str += 'z' + 1;
	int siz = str.size();
	for (int a = 1; a <= 27; a++)
		for (int b = 1; b <= 27; b++)
		{
			ans = cnt = 0;
			for (int i = 0; i < siz; i++)
			{
				if (str[i] - 'a' + 1 == b) ans += cnt;
				if (str[i] - 'a' + 1 == a) cnt++;
			}
			maxi = max(maxi, ans);
		}
	printf("%lld", maxi);
	return 0;
}