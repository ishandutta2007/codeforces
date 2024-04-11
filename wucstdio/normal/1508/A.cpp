#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,cnt[3][2];
char s[3][200005];
void print(char*s,char*t,bool f)
{
	int i=1,j=1;
	for(int k=1;k<=n;k++)
	{
		while(s[i]-'0'!=f)putchar(s[i]),i++;
		while(t[j]-'0'!=f)putchar(t[j]),j++;
		putchar(s[i]);
		i++,j++;
	}
	while(i<=2*n)putchar(s[i]),i++;
	while(j<=2*n)putchar(t[j]),j++;
	putchar('\n');
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s%s%s",s[0]+1,s[1]+1,s[2]+1);
		for(int i=0;i<3;i++)
		{
			cnt[i][0]=cnt[i][1]=0;
			for(int j=1;j<=2*n;j++)
			  cnt[i][s[i][j]-'0']++;
		}
		if(cnt[0][0]>=n&&cnt[1][0]>=n)print(s[0],s[1],0);
		else if(cnt[0][1]>=n&&cnt[1][1]>=n)print(s[0],s[1],1);
		else if(cnt[0][0]>=n&&cnt[2][0]>=n)print(s[0],s[2],0);
		else if(cnt[0][1]>=n&&cnt[2][1]>=n)print(s[0],s[2],1);
		else if(cnt[1][0]>=n&&cnt[2][0]>=n)print(s[1],s[2],0);
		else if(cnt[1][1]>=n&&cnt[2][1]>=n)print(s[1],s[2],1);
	}
	return 0;
}