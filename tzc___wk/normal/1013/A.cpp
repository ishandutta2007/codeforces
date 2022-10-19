#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> x(1035);
vector<int> y(1035);
bool ok2(int n)
{
	int sum0=0,sum1=0;
	for(int i=0;i<n;i++)
	{
		sum0+=x[i];
		sum1+=y[i];
	}
	if(sum0>=sum1)	return true;
	return false;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
	}
	if(!ok2(n))
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}