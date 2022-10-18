#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t%2==0)
		{
			t--;
		}
		printf("%d ",t);
	}
	return 0;
}