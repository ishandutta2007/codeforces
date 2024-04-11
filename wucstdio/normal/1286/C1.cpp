#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,len[10005],num[105][105][26],top[105],tmp[26];
int cnt1[26],cnt2[26];
char sl[1005],sr[1005],sm[1005],s[100005][105];
bool flag[105][10005];
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
	    printf("? %d %d\n",1,1);
	    fflush(stdout);
	    scanf("%s",sm);
	    printf("! %s\n",sm);
	    return 0;
	}
	printf("? %d %d\n",1,n);
	fflush(stdout);
	memset(top,0,sizeof(top));
	for(int i=1;i<=n*(n+1)/2;i++)
	{
		scanf("%s",s[i]+1);
		len[i]=(int)strlen(s[i]+1);
		top[len[i]]++;
		for(int j=0;j<26;j++)num[len[i]][top[len[i]]][j]=0;
		for(int j=1;j<=len[i];j++)num[len[i]][top[len[i]]][s[i][j]-'a']++;
	}
	printf("? %d %d\n",2,n);
	fflush(stdout);
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		scanf("%s",s[i]+1);
		len[i]=(int)strlen(s[i]+1);
		for(int j=0;j<26;j++)tmp[j]=0;
		for(int j=1;j<=len[i];j++)tmp[s[i][j]-'a']++;
		for(int j=1;j<=top[len[i]];j++)
		{
			if(flag[len[i]][j])continue;
			bool f=0;
			for(int k=0;k<26;k++)
			{
				if(tmp[k]!=num[len[i]][j][k])
				{
					f=1;
					break;
				}
			}
			if(f==0)
			{
				flag[len[i]][j]=1;
				break;
			}
		}
	}
	printf("! ");
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=top[i];j++)
		{
			if(flag[i][j])continue;
			for(int k=0;k<26;k++)
			{
				num[i][j][k]-=tmp[k];
				if(num[i][j][k])
				{
					tmp[k]++;
					putchar(k+'a');
				}
			}
		}
	}
	putchar('\n');
	return 0;
}