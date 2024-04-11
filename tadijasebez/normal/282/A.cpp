#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x=0;
	string s;
	scanf("%i",&n);
	while(n--)
	{
		cin>>s;
		if(s[0]=='+' || s[2]=='+') x++;
		else x--;
	}
	printf("%i\n",x);
	return 0;
}