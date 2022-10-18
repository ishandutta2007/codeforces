#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
using namespace std;
main()
{
	long long n,w,b;
	cin>>n>>w>>b;
	long long arr[n];
	for(long long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long mid = n/2;
	long long count =0;
	long long f= 0;
	for(long long i=0;i<mid;i++)
	{
		{
			if(arr[i] == 2)
			{
				if(arr[n-i-1] != 2)
				{
					if(arr[n-i-1] == 0)
					{
						count += w;
					}
					else
					{
						count += b;
					}
				}
				else
				{
					if(w<b)
					{
						count += 2 * w;
					}
					else
					{
						count += 2 * b;
					}
				}
			}
			else
			{
			//	cout<<mid<<endl;
				if(arr[n-i-1] == 2)
				{
					if(arr[i] == 0)
					{
						count += w;
					}
					else
					{
						count += b;
					}
				}
				else if(arr[i] != arr[n-i-1])
				{
					
					f= 1;
					break;
				}
			}
		}
	}
	if(n%2 != 0)
	{
		if(arr[n/2] == 2)
		{
			if(w<b)
			{
				count += w;
			}
			else
			{
				count += b;
			}
		}
	}
	if(f== 1)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<count<<endl;
	}
}