#include <iostream>
#include <cmath> 
using namespace std;
int main()
{	
	int n;
	cin>>n;
	int s=sqrt(n);
	while(n>0)
	{
		int t=((n-1)/s)*s;
		for (int i=t+1;i<=n;i++)
			cout<<i<<" ";
		n=t;
	}
	return 0;
}