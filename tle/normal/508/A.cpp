#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,m,k,a,b;
bool p[1010][1010];
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b;
		p[a][b]=1;
		bool os=0;
		for(int j=a-1;j<=a;j++)
		{
			for(int k=b-1;k<=b;k++)
			{
				if(p[j][k]&&p[j+1][k]&&p[j+1][k+1]&&p[j][k+1]) os=1;
			}
		}
		if(os)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<0;
}