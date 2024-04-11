/***
3
add 1
remove
add 2
add 3
remove
remove
***/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	stack<ll>virsus;
	ll n;
	cin >> n;
	n *= 2;
	ll ans = 0;
	ll i = 1;
	while (n--)
	{
		string a;
		cin >> a;
		if (a == "add")
		{
			ll k;
			cin >> k;
			virsus.push(k);
		}
		if (a == "remove")
		{
			if (!virsus.empty())
			{
				if (virsus.top() != i)
				{
					ans++;
					while (!virsus.empty())
						virsus.pop();
				}
				else
					virsus.pop();
			}
			i++;
		}
	}
	cout << ans;
}