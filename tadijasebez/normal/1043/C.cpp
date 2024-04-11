#include <bits/stdc++.h>
using namespace std;
const int N=1050;
char s[N],t[N];
bool sw[N];
int main()
{
	int n,i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	//for(i=1;i<=n;i++) t[i]=s[i];
	j=1;s[n+1]='b';
	for(i=1;i<=n;i++)
	{
		if(s[i]!=s[i+1])
		{
			sw[i]=1;
			//reverse(s+1,s+i+1);
		}
	}
	for(i=1;i<=n;i++) printf("%i ",sw[i]);
	//printf("%s\n",s+1);
	//for(i=1;i<=n;i++) if(sw[i]) reverse(t+1,t+i+1);
	//printf("%s\n",t+1);
	return 0;
}