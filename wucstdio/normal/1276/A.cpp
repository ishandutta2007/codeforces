#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,res[1500005];
char s[1500005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=(int)strlen(s+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')s[i]='z',res[++ans]=i;
		}
		for(int i=2;i<n;i++)
		{
			if(s[i-1]=='t'&&s[i]=='w'&&s[i+1]=='o')s[i]='z',res[++ans]=i;
			if(s[i-1]=='o'&&s[i]=='n'&&s[i+1]=='e')s[i]='z',res[++ans]=i;
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++)printf("%d ",res[i]);
		printf("\n");
	}
	return 0;
}