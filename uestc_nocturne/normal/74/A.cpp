#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
string ret,ch;
int n,i,j,te,ma,x,y;
int main()
{
	while(~scanf("%d",&n))
	{
		ma=-1000000000;
		for(i=0;i<n;i++)
		{
			cin>>ch;
			scanf("%d%d",&x,&y);
			te=100*x-50*y;
			for(j=0;j<5;j++)
			{scanf("%d",&x);te+=x;}
			if(te>ma)
			{
				ma=te;
				ret=ch;
			}
		}
		cout<<ret<<endl;
	}
}