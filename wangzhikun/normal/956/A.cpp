#include<cstdio>
using namespace std;
int column[55],n,m,i,j,cnt=0,k,l;
char s[55];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		k=0;
		scanf("%s",s);
		for(j=0;j<m;j++)
		{
			if(s[j]=='#')
			{
				if(column[j])k=column[j];
				else k=-1,++cnt;
				for(l=0;l<m;l++)
				{
					if(s[l]=='.'&&column[l]==k)
					{
						printf("no");
						return 0;
					}
					if(s[l]=='#')
					{
						if(k!=-1&&column[l]!=k)
						{
							printf("no");
							return 0;
						}
						if(k==-1&&column[l])
						{
							printf("no");
							return 0;
						}
						if(k==-1)column[l]=cnt;
					}
				}
				break;
			}
		}
	}
	printf("yes");
	return 0;
}