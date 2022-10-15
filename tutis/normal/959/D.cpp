/*input
5
2 3 5 4 13
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>divisors[4000009];
int main()
{
	set<int>nepanaudoti;
	for (int i = 2; i < 4000009; i++)
	{
		if (divisors[i].empty())
		{
			nepanaudoti.insert(i);
			for (int j = i; j < 4000009; j += i)
			{
				divisors[j].push_back(i);
			}
		}
	}
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool didesnis = false;
	for (int i = 0; i < n; i++)
	{
		if (!didesnis)
		{
			bool tinka = true;
			for (int p : divisors[a[i]])
			{
				if (nepanaudoti.count(p) == 0)
				{
					tinka = false;
				}
			}
			if (tinka)
			{
				b[i] = a[i];
				for (int p : divisors[b[i]])
					nepanaudoti.erase(p);
			}
			else
			{
				didesnis = true;
				for (b[i] = a[i] + 1;; b[i]++)
				{
					bool tinka = true;
					for (int p : divisors[b[i]])
					{
						if (nepanaudoti.count(p) == 0)
						{
							tinka = false;
						}
					}
					if (tinka)
						break;
				}
				for (int p : divisors[b[i]])
					nepanaudoti.erase(p);
			}
		}
		else
		{
			b[i] = *nepanaudoti.begin();
			nepanaudoti.erase(nepanaudoti.begin());
		}
	}
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
}