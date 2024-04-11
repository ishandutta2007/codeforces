#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%3==0)
	{
		printf("1 1 %d",n-2);
	}
	if(n%3==1)
	{
		printf("1 1 %d",n-2);
	}
	if(n%3==2)
	{
		printf("1 2 %d",n-3);
	}
	return 0;
}