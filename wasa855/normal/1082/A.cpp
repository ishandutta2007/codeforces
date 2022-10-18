#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
void work()
{
	int n,x,y,d;
	cin>>n>>x>>y>>d;
	int ans=INF;
	if(abs(y-x)%d==0)
	{
		if((abs(y-x)/d)<ans)
		{
			ans=abs(y-x)/d;
		}
	}
	if((y-1)%d==0)
	{
		if((y-1)/d+(x-1)/d+(bool)((x-1)%d)<ans)
		{
			ans=(y-1)/d+(x-1)/d+(bool)((x-1)%d);
		}
	}
	if((n-y)%d==0)
	{
		if((n-y)/d+(n-x)/d+(bool)((n-x)%d)<ans)
		{
			ans=(n-y)/d+(n-x)/d+(bool)((n-x)%d);
		}
	}
	if(ans!=INF)
	{
		cout<<ans<<endl;
	}
	else
	{
		cout<<"-1\n";
	}
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		work();
	}
	return 0;
}