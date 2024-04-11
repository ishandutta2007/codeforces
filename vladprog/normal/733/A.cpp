#include <bits/stdc++.h>

using namespace std;

int  notvov(char c)
{
	if(c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U' ||c=='Y')
	 return 0;
	return 1;
}
int main()
{
	char s[1000];
	cin >> s;
	int n=strlen(s);
	int  ans=1;
	for(int i=0;i<n;i++)
	{
		int  c=1;
		while(i<n && notvov(s[i]))
		{
			c++;i++;
		} 
		ans = max(c,ans);
	}
	 cout << ans ;
	return 0;
}