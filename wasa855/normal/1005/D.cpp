#include<bits/stdc++.h>
using namespace std;
char a[200005];
int main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		a[i]-='0';
		a[i]%=3;
	}
	int ans=0;
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			ans++;
			last=0;
			continue;
		}
		if(a[i]+last==3)
		{
			ans++;
			last=0;
			continue;
		}
		if(last==0)
		{
			last=a[i];
			continue;
		}
		if(i==n)
		{
			break;
		}
		i++;
		ans++;
		last=0;
	}
	cout<<ans<<endl;
	return 0;
}