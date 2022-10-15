#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool palind(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != a[a.length() - i - 1])
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		char x=a[i];
		for(a[i]='a';a[i]<='z';a[i]++)
		{
			if(a[i]==x)
			{
				continue;
			}
			if(palind(a))
			{
				cout<<"YES";
				return 0;
			}
		}
		a[i]=x;
	}
	cout<<"NO";
	return 0;
}