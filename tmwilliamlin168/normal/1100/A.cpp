#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,k,sums=0;cin>>n>>k;
	int a[101];
	int sum[101]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum[i%k]+=a[i];
		sums+=a[i];
	}
	int maxi=0;
	for(int i=0;i<k;i++)
	{
	//	cout<<sum[i]<<" ";		
		maxi=max(maxi,int(fabs(sums-sum[i])));
	}
	cout<<maxi;
}