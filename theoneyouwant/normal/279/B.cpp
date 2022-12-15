#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {
	int n,maxlength=0,a1=0,a2=0;
	long long int t;
	bool c=0;
	cin>>n>>t;
	int a[n+1];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	    if(a[i]<=t)
	    {
	        c=1;
	    }
	}
	a[n]= INT_MIN;
	if(c==0)
	{
	    cout<<"0";
	}
	else
	{
	    int j;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<=t)
	        {
	            j=i;
	            break;
	        }
	    }
	    a1=j;a2=j;maxlength=1;
	    long long int sum=a[j];
	    while(a2<=(n-1))
	    {
	        while(sum+a[a2+1]<=t && a2<n-1)
	        {
	            sum+=a[a2+1];
	            a2+=1;
	        }
	        maxlength = max(maxlength,a2-a1+1);
	        if(a1==a2)
	        {
	            a2++;
	            sum=sum+a[a2];
	        }
	        a1++;
	        sum=sum-a[a1-1];
	    }
	    cout<<maxlength;
	}
	
	return 0;
}