#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[10005];
int n,a[10005],b[10005],num;
bool flag[10005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)flag[i]=s[i]-'0';
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	int now=0;
	for(int i=1;i<=n;i++)now+=flag[i];
	int ans=now;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>=b[j]&&(i-b[j])%a[j]==0)
			{
				flag[j]^=1;
				if(flag[j])now++;
				else now--;
			}
		}
		ans=max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}