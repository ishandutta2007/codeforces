#include<bits/stdc++.h>
using namespace std;
const int max_n=2e4+5;
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		int pos=-1;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0')
			{
				pos=i;
				break;
			}
		}
		int l1,r1,l2,r2;
		if(pos!=-1)
		{
			if(pos<=(n+1)/2)
				l1=pos,r1=pos+n/2,l2=pos+1,r2=pos+n/2;
			else
				l1=pos-n/2,r1=pos,l2=pos-n/2,r2=pos-1;
		}
		else
			l1=1,r1=n/2,l2=2,r2=n/2+1;
		assert(l1>=1&&l1<=n&&r1>=1&&r1<=n&&r1-l1+1>=n/2);
		assert(l2>=1&&l2<=n&&r2>=1&&r2<=n&&r2-l2+1>=n/2);
		printf("%d %d %d %d\n",l1,r1,l2,r2);
	}
    return 0;
}