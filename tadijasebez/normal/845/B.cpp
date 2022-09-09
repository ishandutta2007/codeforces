#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[6];
	scanf("%s",s);
	int sol=6,i,j;
	for(i=0;i<1e7;i++)
	{
		int x=0,y=0,tmp=i,ans=0;
		for(j=0;j<6;j++)
		{
			int c=tmp%10;
			tmp/=10;
			if(c!=s[j]-'0') ans++;
			if(j<3) x+=c;
			else y+=c;
		}
		if(x==y) sol=min(sol,ans);
	}
	printf("%i\n",sol);
	return 0;
}