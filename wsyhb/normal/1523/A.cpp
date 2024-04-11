#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+5;
char s[max_n],t[max_n];
int main()
{
	int t0;
	scanf("%d",&t0);
	while(t0--)
	{
		int n,m;
		scanf("%d%d%s",&n,&m,s+1);
		int T=min(m,n);
		while(T--)
		{
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='1')
					t[i]='1';
				else
				{
					int cnt=(i>1&&s[i-1]=='1')+(i<n&&s[i+1]=='1');
					t[i]='0'+(cnt==1);
				}
			}
			for(int i=1;i<=n;++i)
				s[i]=t[i];
		}
		printf("%s\n",s+1);
	}
	return 0;
}