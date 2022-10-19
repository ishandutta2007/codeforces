#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char a[200001],b[200001];
bool lt[100][100],tans[100][100];
int main()
{
	int t,n,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
    { 
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		flag=false;
		for(int i=1;i<=30;i++)for(int j=1;j<=30;j++)lt[i][j]=false,tans[i][j]=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i])
			{
				printf("-1\n");
				flag=true;
				break;
			}
			lt[a[i]-'a'+1][b[i]-'a'+1]=1;
		}
		if(flag==true)continue;
		ans=0;
		for(int i=1;i<=30;i++)
		{
			for(int j=i+1;j<=30;j++)
			{
				if(lt[i][j]==true)
				{
					for(int k=j+1;k<=30;k++)
					{
						if(lt[j][k]==false)lt[j][k]=lt[i][k];
					}
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}