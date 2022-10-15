/*input
15 3
cccaabababaccbc
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int kiek[26];
	fill_n(kiek, 26, 0);
	for (char x : s)
		kiek[x - 'a']++;
	for (int t = 0; t < 26; t++)
	{
		if (k >= kiek[t])
		{
		}
		else
		{
			kiek[t] = max(0, k);
		}
		k -= kiek[t];
	}
	for (char x : s)
	{
		if (kiek[x - 'a'] <= 0)
			cout << x;
		kiek[x - 'a']--;
	}



}