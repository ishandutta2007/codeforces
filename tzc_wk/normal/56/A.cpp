#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define INF 0x3f3f3f3f
string drinks[15]={"ABSINTH","BEER","BRANDY","CHAMPAGNE","GIN","RUM","SAKE","TEQUILA","VODKA","WHISKEY","WINE"};
int main()
{
	int n,ans=0;
	string s;
	cin>>n;
	for(int e=0;e<n;e++)
	{
		cin>>s;
		if (isupper(s[0]))
		{
			for(int i=0;i<11;i++)
			{
				if(drinks[i]==s)
				{
					ans++;
					break;
				}
			}
		}
		else
		{
			int d=0;
			for(int i=0;i<s.size();i++)
			{
				d=d*10+s[i]-'0';
			}
			if(d<18)	ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}