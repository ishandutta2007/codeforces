#include <bits/stdc++.h>
using namespace std;
bool res[110]={false};
int main()
{
	int n;
	int a[110];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cmp=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==cmp)
		{
			cmp++;
			res[i]=1;
		}
	}
	cmp--;
	cout<<cmp<<endl;
	if(cmp)
	{
		int p=0;
		for(int i=0;i<n;i++)
		{
			if(res[i])
			{
				if(p++)
				cout<<" ";
				cout<<2000+i+1;
			}
		}
		cout<<endl;
	}
	return 0;
}