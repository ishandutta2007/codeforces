#include <iostream>

using namespace std;

int a[1000000];

int main()
{
	int n,t;
	cin>>n>>t;
	
	for(int i=0;i<n-1;++i)
	{
		cin>>a[i];
	}
	
	
	int current = 1;
	
	while(current < t)
	{
		current = current + a[current-1];
	}
	
	if(current == t)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return 0;
}