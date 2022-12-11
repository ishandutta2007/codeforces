#include <bits/stdc++.h>
using namespace std;
int n,k,sum=0;
int a[10];
char s[100007];
int main()
{
	scanf("%d",&k);
	scanf("%s",s);
	n=strlen(s);
	memset(a,0,sizeof(a));
	for (int i=0;i<n;i++)
		++a[s[i]-'0'];
	sum=0;
	for (int i=1;i<=9;i++)
		sum+=i*a[i];
	if (sum>=k) printf("%d\n",0); else
	{
		sum=k-sum;
		int ans=0;
		for (int i=0;i<=9;i++)
			if (sum<=(9-i)*a[i]) 
			{
				printf("%d\n",ans+((sum+(9-i)-1)/(9-i)));
				break;
			}
			else 
			{
				sum-=(9-i)*a[i];
				ans+=a[i];
			}
	}
	return 0;
}