#include <bits/stdc++.h>
using namespace std;
int n,m,cnt1[505],cnt2[505],tot,pos;
string str[505]; 
int tag;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>str[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			cnt1[i]+=str[i][j]=='*',cnt2[j]+=str[i][j]=='*';
	tag=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt1[i]&&!tag) tag=true;
		if(!cnt1[i]&&tag==1) tag=2;
		if(tag==2&&cnt1[i])
		{
			printf("No");
			return 0;
		}
	}
	tag=0;
	for(int i=0;i<m;i++)
	{
		if(cnt2[i]&&!tag) tag=1;
		if(!cnt2[i]&&tag==1) tag=2;
		if(tag==2&&cnt2[i])
		{
			printf("No");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(cnt1[i]&&cnt1[i]!=1)
			tot++;
	if(tot!=1)
	{
		printf("No");
		return 0;
	}
	tot=0;
	for(int i=0;i<m;i++)
		if(cnt2[i]&&cnt2[i]!=1)
			tot++;
	if(tot!=1)
	{
		printf("No");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(cnt1[i]!=1&&cnt1[i]) pos=i;
	for(int i=0;i<m;i++)
		if(cnt2[i]!=1&&cnt2[i])
		{
			if(pos!=1&&pos!=n&&i&&i!=m-1&&str[pos][i]=='*'&&str[pos-1][i]=='*'&&str[pos+1][i]=='*'&&str[pos][i-1]=='*'&&str[pos][i+1]=='*')
			{
				printf("Yes");
				return 0;
			}
			else
			{
				printf("No");
				return 0;
			}
		}
}