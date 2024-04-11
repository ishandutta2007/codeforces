#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	int k=sqrt(m);
	int sum=m/k;
	for(int i=1;i<=sum;i++)
	{
		for(int j=m-k*i+1;j<=m-k*(i-1);j++)
		{
			printf("%d ",j);
		}
	}
	for(int i=1;i<=m-m/k*k;i++)
	{
		printf("%d ",i);
	}
	cout<<"\n";
	return 0;
}