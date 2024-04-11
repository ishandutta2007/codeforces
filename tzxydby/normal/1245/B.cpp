#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N],ans[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b,c,k=0;
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			ans[i]='@';
			if(s[i]=='R')
			{
				if(b)
				{
					b--;
					k++;
					ans[i]='P';
				}
			}
			if(s[i]=='P')
			{
				if(c)
				{
					c--;
					k++;
					ans[i]='S';
				}
			}
			if(s[i]=='S')
			{
				if(a)
				{
					a--;
					k++;
					ans[i]='R';
				}
			}
		}
		if(k>=(n+1)/2)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				if(ans[i]=='@')
				{
					if(a) printf("R"),a--;
					else if(b) printf("P"),b--;
					else if(c) printf("S"),c--;
				}
				else
					printf("%c",ans[i]);
			}
			puts("");
		}
		else
			puts("NO");
	}
	return 0;
}