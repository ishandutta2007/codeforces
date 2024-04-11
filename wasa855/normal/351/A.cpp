#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x;
	int n;
	cin>>n;
	int t;
	double sum=0;
	int zheng=0;
	for(int i=1;i<=n*2;i++)
	{
		cin>>x;
		t=x;
		sum+=x-t;
		if(x-t<1e-9)
		{
			zheng++;
		}
	}
	double ans=1e5;
	for(int i=0;i<=min(n,zheng);i++)
	{
		ans=min(ans,abs(sum-(n-i)));
	}
	printf("%.3lf\n",ans);
	return 0;
}