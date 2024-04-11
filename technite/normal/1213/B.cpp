#include<iostream>
using namespace std;
int main()
{
	int t,n,i,min,count;
	cin>>t;
	while(t--)
		{
			cin>>n;
			min=1000000;
			count=0;
			int a[n];
			for(i=0;i<n;i++)
				{	
					cin>>a[i];
				}
			for(i=n-1;i>=0;i--){
			if(a[i]>min) count++;
			else min=a[i];
			}
			cout<<count<<endl;
			}
return 0;}