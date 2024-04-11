#include <bits/stdc++.h>
using namespace std;
char str[100000];
double ans=0;
int flag[200];
int main()
{
	cin>>str;
	memset(flag,0,sizeof(flag));
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		flag[str[i]]++;
	}
	for(int i='0';i<='z';i++)
	{
		ans+=(double)flag[i]*flag[i];
	}
	printf("%.0lf\n",ans);
	ans=0;
	return 0;
}//