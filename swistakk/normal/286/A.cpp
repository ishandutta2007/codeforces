#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#define uint long long int
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	if(n%4 >=2)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i=1; i<=n/2; i++)
	{
		if(i%2==1)
		{
			cout<<i+1<<" ";
		}
		if(i%2==0)
		{
			cout<<n-i+2<<" ";
		}
	}
	if(n%2==1)
	{
		cout<<n/2+1<<" ";
	}
	for(int i=(n+3)/2; i<=n; i++)
	{
		if((n-i)%2==0)
		{
			cout<<i-1<<" ";
		}
		else
		{
			cout<<n-i<<" ";
		}
	}
	cout<<endl;
	//system("pause");
	return 0;
}