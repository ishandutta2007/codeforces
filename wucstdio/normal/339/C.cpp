#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,num,pos[15],f[2005][25][25],to[2005][25][25],ans[2005],top;
inline int read()
{
	char c=getchar();
	while(c!='0'&&c!='1')c=getchar();
	return c=='1';
}
int main()
{
	for(int i=1;i<=10;i++)
	{
		pos[i]=read();
		num+=pos[i];
	}
	scanf("%d",&m);
	if(m==0)
	{
		printf("YES\n");
		return 0;
	}
	if(num==0)
	{
		printf("NO\n");
		return 0;
	}
	if(m==1)
	{
		printf("YES\n");
		for(int i=1;i<=10;i++)
		if(pos[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
	f[0][0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(!pos[j])continue;
			if(i==1)
			{
				f[i][j][j]=1;
				continue;
			}
			for(int cha=1;cha<=10;cha++)
			{
				if(f[i][cha][j])continue;
				if(j<cha)continue;
				for(int last=1;last<=10;last++)
				{
					if(last==j||!pos[last])continue;
					if(f[i-1][j-cha][last])
					{
						f[i][cha][j]=1;
						to[i][cha][j]=last;
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(f[m][i][j])
			{
				printf("YES\n");
				top=0;
				int now1=m,now2=i,now3=j;
				while(now1!=0||now2!=0||now3!=0)
				{
					ans[++top]=now3;
					int xx=now3;
					now3=to[now1][now2][now3];
					now2=xx-now2;
					now1--;
				}
				for(int i=top;i>=1;i--)
				  printf("%d ",ans[i]);
				printf("\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}