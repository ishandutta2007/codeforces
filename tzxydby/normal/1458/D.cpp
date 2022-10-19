#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int t,n,a[N],b[N];
char s[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int r=500000;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				a[r]++;
				r--;	
			}
			else
			{
				b[r]++;
				r++;
			}
		}
		r=500000;
		for(int i=1;i<=n;i++)
		{
			if(a[r]&&(b[r-1]||b[r]==0))
			{
				printf("0");
				a[r]--;
				r--;
			}
			else
			{
				printf("1");
				b[r]--;
				r++;
			}
		}
		puts("");
	}
	return 0;
}