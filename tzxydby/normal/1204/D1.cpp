#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N];
int f[N];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),x=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
			if(x)
				x--;
		if(s[i]=='1')
		{
			x++;
			f[x]=i;
		}	
	}
	while(x)
	{
		s[f[x]]='0';
		x--;	
	}
	printf("%s\n",s+1);
	return 0;
}