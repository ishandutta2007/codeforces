/*input
3+2+1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	vector<int>sk;

	string a;
	cin >> a;
	for (int i = 0; i <= a.size(); i++)
	{
		if (i >= a.size() || a[i] == '+')
		{
			string x;
			for (int j = 0; j < i; j++)
			{
				x.push_back(a[j]);
			}
			sk.push_back(stoi(x));
			break;
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '+')
		{
			string x;
			for (int j = i + 1; j <= a.size(); j++)
			{
				if (j >= a.size() || a[j] == '+')
				{
					sk.push_back(stoi(x));
					break;
				}
				x.push_back(a[j]);
			}
		}
	}



	sort(sk.begin(), sk.end());
	for (int i = 0; i < sk.size(); i++)
	{
		cout << sk[i];
		if (i != sk.size() - 1)
			cout << "+";
	}
}