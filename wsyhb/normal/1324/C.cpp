#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=2e5+5;
char s[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int n=strlen(s),now=0,ans=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='L') now++;
			else
			{
				ans=max(ans,now+1);
				now=0;
			}
		}
		ans=max(ans,now+1);
		printf("%d\n",ans); 
	}
	return 0;
}