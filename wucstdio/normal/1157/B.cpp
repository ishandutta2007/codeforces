#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,f[15];
char s[200005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=9;i++)scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	{
		if(f[s[i]-'0']>s[i]-'0')
		{
			int j=i;
			while(j<=n&&f[s[j]-'0']>=s[j]-'0')
			{
				s[j]=f[s[j]-'0']+'0';
				j++;
			}
			break;
		}
	}
	printf("%s\n",s+1);
	return 0;
}