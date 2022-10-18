#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	if(x>y)
	{
		cout<<n<<endl;
		return 0;
	}
	int t;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t<=x)
		{
			ans++;
		}
	}
	cout<<(ans/2+ans%2)<<endl;
	return 0;
}