#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[105];
	scanf("%s",a);
	int x=0,y=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='-')
		{
			x++;
		}
		else
		{
			y++;
		}
	}
	if(x==0)
	{
		cout<<"YES";
	}
	else if(y==0)
	{
		cout<<"YES";
	}
	else if(x%y==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}