#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,k=0,l=0,sum=0;
	cin>>n;
	int a[n],a1[n],a2[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)
		{
			a1[k]=a[i];
			k++;
		}
		else
		{
			a2[l]=a[i];
			l++;
		}
	}
	sort(a1,a1+k);
	sort(a2,a2+l);
	if(abs(k-l)==1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	else if(k>l)
	{
	for(i=0;i<(k-l)-1;i++)
	{
		sum+=a1[i];
	}
	}
	else
	{
		for(i=0;i<(l-k)-1;i++)
		{
			sum+=a2[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}