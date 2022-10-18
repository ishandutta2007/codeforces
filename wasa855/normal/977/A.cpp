#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		if(m%10==0)
		{
			m/=10;
		}
		else
		{
			m--;
		}
	}
	cout<<m<<endl;
	return 0;
}