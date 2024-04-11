#include<bits/stdc++.h>
using namespace std;
int data[400005];
int main()
{
	int n;
	cin>>n;
	char a;
	int b;
	cin>>a>>b;
	int l=200000,r=200000;
	data[b]=200000;
	for(int i=2;i<=n;i++)
	{
		cin>>a>>b;
		if(a=='L')
		{
			l--;
			data[b]=l;
		}
		else if(a=='R')
		{
			r++;
			data[b]=r;
		}
		else
		{
			printf("%d\n",min(data[b]-l,r-data[b]));
		}
	}
	return 0;
}