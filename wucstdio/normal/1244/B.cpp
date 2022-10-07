#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int l=n+1,r=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		if(l==n+1&&r==0)printf("%d\n",n);
		else printf("%d\n",max(r*2,(n-l+1)*2));
	}
	return 0;
}