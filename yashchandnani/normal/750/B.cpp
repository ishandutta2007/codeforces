#include <bits/stdc++.h>
using namespace std;

int main()
{	int n;
	long int temp =0,t=0 ;
	char s[7];
	scanf("%d\n",&n);
	int i;
	for (i = 0; i < n; ++i)
	{
		scanf("%ld %s",&temp,s);
		
		if (s[0]=='N')
		{	
			t=t-temp;
		}
		else if (s[0]=='S')
		{	
			t=t+temp;
		}
		else
		{
			if ((t>0)&&(t<20000))
			{
				continue;
			}
			else {
				printf("No");
				return 0;
			}
		}
		if ((t>=0)&&(t<=20000))
		{	
			continue;
		}
		printf("No");
		return 0;
	}
	if (t==0)
	{
		cout<<"YES";
	}
	else cout<<"NO";
	return 0;
}