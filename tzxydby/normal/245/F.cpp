#include<bits/stdc++.h>
using namespace std;
int Mo[14]={0,31,29,31,30,31,30,31,31,30,31,30,31};
char str[5000005];
vector<int>a;
int main()
{
	int n,m,Month,Date,Hour,Minute,Second,ans=-1;
	scanf("%d%d\n",&n,&m);
	while(~scanf("2012-%d-%d",&Month,&Date))
	{
		scanf("%d:%d:%d:",&Hour,&Minute,&Second);
		getchar();
		gets(str);
		int sum=Date;
		for(int i=1;i<Month;i++)
			sum+=Mo[i];
		sum=((sum*24+Hour)*60+Minute)*60+Second;
		a.push_back(sum);
	}
	for(int i=m-1;i<a.size();i++)
	{
		if(a[i]-a[i-m+1]+1<=n)
		{
			ans=a[i];
			break;
		}
	}
	int sum=ans;
	if(sum==-1)
		printf("-1\n");
	else
	{
		Second=sum%60;
		sum/=60;
		Minute=sum%60;
		sum/=60;
		Hour=sum%24;
		sum/=24;
		Month=0;
		Date=sum;
		for(int i=1;i<=12;i++)
		{
			if(Date-Mo[i]>=0)
			{
				Date-=Mo[i];
				Month++;
			}
		}
		printf("2012-%02d-%02d %02d:%02d:%02d\n",Month+1,Date,Hour,Minute,Second);
	}
	return 0;
}