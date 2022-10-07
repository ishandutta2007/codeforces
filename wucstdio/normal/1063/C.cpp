#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
inline int read()
{
	char c=getchar();
	while(c>'z'||c<'a')c=getchar();
	int ans=c=='b';
	while(c>='a'&&c<='z')c=getchar();
	return ans;
}
int main()
{
	scanf("%d",&n);
	int l=0,r=1000000000;
	for(int i=1;i<=min(29,n);i++)
	{
		int mid=(l+r)>>1;
		printf("%d 500000000\n",mid);
		fflush(stdout);
		int c=read();
		if(c)l=mid;
		else r=mid;
	}
	if(n<=29)
	{
		printf("%d %d %d %d\n",l,500000001,r,499999999);
		fflush(stdout);
		return 0;
	}
	printf("%d 600000000\n",l);
	fflush(stdout);
	int c=read();
	if(c)printf("%d %d %d %d\n",l,499999999,r,500000001);
	else printf("%d %d %d %d\n",l,500000001,r,499999999);
	fflush(stdout);
	return 0;
}