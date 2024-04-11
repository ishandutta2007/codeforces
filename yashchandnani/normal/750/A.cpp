#include <bits/stdc++.h>
using namespace std;

int main()
{	int n,k,i;
	cin>>n;
	cin>>k;
	k=240-k;
	k=k/5;
	for ( i = 1; (i <= n)&&(k>=i); ++i)
	{
		k=k-i;
	}
	cout<<i-1;
	if (k<0)
		return 0;
}