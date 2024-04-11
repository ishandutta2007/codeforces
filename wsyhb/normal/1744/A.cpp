#include<bits/stdc++.h>
using namespace std;
const int max_n=50+5;
int a[max_n];
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		scanf("%s",s+1);
		bool ans=true;
		for(int i=1;i<=50;++i)
		{
			char ch='*';
			for(int j=1;j<=n;++j)
			{
				if(a[j]==i)
				{
					if(ch=='*')
						ch=s[j];
					else if(s[j]!=ch)
					{
						ans=false;
						break;
					}
				}
			}
			if(!ans)
				break;
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}