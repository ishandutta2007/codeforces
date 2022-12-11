#include<bits/stdc++.h>
using namespace std;
int k;
const char c[5]={'a','e','i','o','u'};
char Ans[105][10005];
int main()
{
	cin>>k;
	bool yes=0;
	int nn=0,mm=0;
	for(int n=5;n*n<=k;++n)if(k%n==0)
	{
		int m=k/n;
		int p=0;
		for(int j=1;j<=m;++j)
		{
			++p;p%=5;
			for(int i=0;i<n;++i)
			{
				Ans[i][j]=c[(i+p)%5];
			}
		}
		yes=1;
		nn=n;mm=m;
		break;
	}
	if(!yes)
	{
		puts("-1");
		return 0;
	}
	else
	{
		for(int i=0;i<nn;++i)
		{
			for(int j=1;j<=mm;++j)printf("%c",Ans[i][j]);
		}
	}
}