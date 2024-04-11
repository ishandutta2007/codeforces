#include <bits/stdc++.h>
using namespace std;

int main(){

	int a[5]={0},b[5]={0},x,y,z;
	for (int i = 1; i < 5; ++i)
	{
		cin>>x>>y>>z>>a[i%4];
		if (x)
		{
			b[i%4]=1;
			b[(i+3)%4]=1;
		}
		if (y)
		{
			b[i%4]=1;
			b[(i+2)%4]=1;
		}
		if (z)
		{
			b[i%4]=1;
			b[(i+1)%4]=1;
		}
	}
	
	for (int i = 0; i < 4; ++i)
	{
		if (a[i]==1&&b[i]==1)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}