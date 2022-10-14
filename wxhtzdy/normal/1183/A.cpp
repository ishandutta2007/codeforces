#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>
#define f first
#define s second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while(true)
	{
		int brojac = 0;
		int npom = n;
		while(npom > 0)
		{
			brojac += npom % 10;
			npom /= 10;
		}
		if(brojac % 4 == 0)
		{
			break;
		}
		n++;
	}
	cout << n << '\n';
	return 0;
}