#include<bits/stdc++.h>
using namespace std;
int x,y,a,b;
int main()
{
	scanf("%d%d%d%d",&x,&y,&a,&b);
	if(x==a||y==b)
	{
		int ans=2*abs(x-a)+2*abs(y-b)+6;
		cout<<ans<<endl;
	}
	else
	{
		int ans=2*abs(x-a)+2*abs(y-b)+4;
		cout<<ans<<endl;
	}
}