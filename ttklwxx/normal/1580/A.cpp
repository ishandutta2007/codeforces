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
int a[405][405],h[405][405],li[405][405],qz[405][405];
inline int getjz(int x1,int y1,int x2,int y2)
{
	return qz[x2][y2]-qz[x1-1][y2]-qz[x2][y1-1]+qz[x1-1][y1-1];
}
char s[1005];
int main()
{
	int t,n,m,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				a[i][j]=s[j]-'0';
				h[i][j]=h[i][j-1]+a[i][j];
				li[i][j]=li[i-1][j]+a[i][j];
				qz[i][j]=qz[i-1][j]+qz[i][j-1]-qz[i-1][j-1]+a[i][j];
			}
		}
		ans=1000000000;
		for(int i=1;i<=n-4;i++)
		{
			for(int j=1;j<=m-3;j++)
			{
				for(int k=i+4;k<=n;k++)
				{
					for(int l=j+3;l<=m;l++)
					{
						ans=min(ans,2*(l+k-i-j-2)-h[i][l-1]+h[i][j]-li[k-1][j]+li[i][j]-h[k][l-1]+h[k][j]-li[k-1][l]+li[i][l]+getjz(i+1,j+1,k-1,l-1));
						//printf("%d\n",getjz(i+1,j+1,k-1,l-1));
						if((l-j-1+k-i-1)-h[i][l-1]+h[i][j]-li[k-1][j]+li[i][j]+getjz(i+1,j+1,k-1,l-1)>ans)break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}