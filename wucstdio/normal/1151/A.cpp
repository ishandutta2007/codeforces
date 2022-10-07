#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[105];
int n;
int calc(int x,int y)
{
	x-='A',y-='A';
	return min(abs(x-y),26-abs(x-y));
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=10000;
	for(int i=1;i<=n-3;i++)
	  ans=min(ans,calc(s[i],'A')+calc(s[i+1],'C')+calc(s[i+2],'T')+calc(s[i+3],'G'));
	printf("%d\n",ans);
	return 0;
}