#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	/*1
		string a;
		cin>>a;
		int k=0;
		for(int i=0;i<a.length();i++)
		{
			if(a[i]!=a[a.length()-i-1])
				k++;
		}
		if(k==2)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	/*2
	*/
	int N;
	cin >> N;
	string M[N];
	for (int i = 0; i < N; i++)
		cin >> M[i];
	int k = M[0].length();
	int ats = 50 * 60;
	for (int a = 0; a < k; a++)
	{
		int l = a;
		for (int i = 1; i < N; i++)
		{
			int m = 50 * 60;
			for (int b = 0; b < k; b++)
			{
				bool ok = true;
				for (int j = 0; j < k; j++)
				{
					if (M[i][(j - a + k) % k] != M[0][(j - b + k) % k])
					{
						ok = false;
					}
				}
				if (ok)
				{
					m = b;
					break;
				}
			}
			l += m;
		}
		ats = min(ats, l);
	}
	if (ats == 50 * 60)
	{
		cout << -1;
		return 0;
	}
	cout << ats;
	return 0;
}