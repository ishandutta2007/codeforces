#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
char s[1010];
int c[27];
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	int i;
	int ans=0;
	int j=0;
	int k;
	for(i=1;i<=n;i++)
		if(s[i]>='A'&&s[i]<='Z')
		{
			memset(c,0,sizeof c);
			int res=0;
			for(k=j+1;k<=i-1;k++)
			{
				if(!c[s[k]-'a'+1])
					res++;
				c[s[k]-'a'+1]++;
			}
			ans=max(ans,res);
			j=i;
		}
	memset(c,0,sizeof c);
	int res=0;
	for(k=j+1;k<=n;k++)
	{
		if(!c[s[k]-'a'+1])
			res++;
		c[s[k]-'a'+1]++;
	}
	ans=max(ans,res);
	printf("%d\n",ans);
	return 0;
}