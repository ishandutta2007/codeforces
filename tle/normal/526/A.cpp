//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n;
char s[10001];
int main()
{
	cin>>n>>&s[1];
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i+j*4<=n&&s[i]=='*'&&s[i+j]=='*'&&s[i+2*j]=='*'&&s[i+3*j]=='*'&&s[i+4*j]=='*') ok=1;
		}
	}
	if(ok==1) cout<<"yes"; else cout<<"no";
	//***
	return 0;
}