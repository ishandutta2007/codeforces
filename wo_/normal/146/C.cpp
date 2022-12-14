#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	int n=a.size();
	int c=0,d=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='4'&&b[i]=='7')
		{
			c++;
		}
		else if(a[i]=='7'&&b[i]=='4')
		{
			d++;
		}
	}
	printf("%d\n",max(c,d));
}