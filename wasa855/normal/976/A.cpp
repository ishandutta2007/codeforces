#include<bits/stdc++.h>
using namespace std;
char a[105];
int main()
{
	int m;
	cin>>m;
	scanf("%s",a+1);
	if(m==1)
	{
		printf("%s",a+1);
		return 0;
	}
	int num1=0,num0=0;;
	for(int i=1;i<=m;i++)
	{
		if(a[i]=='1')
		{
			num1++;
		}
		else
		{
			num0++;
		}
	}
//	cout<<num1<<" "<<num0;
	cout<<1;
	for(int i=1;i<=num0;i++)
	{
		cout<<0;
	}
	return 0;
}