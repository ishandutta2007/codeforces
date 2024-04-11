#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,s1[100005],s2[100005],a[100005],ans;
inline int read()
{
	char c=getchar();
	while(c!='0'&&c!='1')c=getchar();
	return c=='1';
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&s1[i]);
	for(int i=1;i<=n;i++)
	  s2[i]=(a[i]=read())*s1[i];
	for(int i=1;i<=n;i++)
	  s1[i]+=s1[i-1];
	for(int i=n;i>=1;i--)
	  s2[i]+=s2[i+1];
	ans=s2[1];
	for(int i=n;i>=1;i--)
	  if(a[i])ans=max(ans,s2[i+1]+s1[i-1]);
	printf("%d\n",ans);
	return 0;
}