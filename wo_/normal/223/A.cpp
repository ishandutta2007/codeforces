#include<cstdio>
#include<cstring>

using namespace std;

char ch[100100];
int right[100100],num[100100];

int main()
{
	scanf("%s",ch);
	memset(right,-1,sizeof(right));
	memset(num,-1,sizeof(num));
	int N=strlen(ch);
	if(N<=1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=N-2;i>=0;i--)
	{
		if(ch[i]=='('||ch[i]=='[')
		{
			if((ch[i]=='('&&ch[i+1]==')')||(ch[i]=='['&&ch[i+1]==']'))
			{
				if(right[i+2]==-1)
				{
					right[i]=i+1;
					num[i]=(ch[i]=='['?1:0);
				}
				else
				{
					right[i]=right[i+2];
					num[i]=num[i+2]+(ch[i]=='['?1:0);
				}
			}
			else if((ch[i]=='('&&ch[i+1]==']')||(ch[i]=='['&&ch[i+1]==')'))
			{
				continue;
			}
			else
			{
				if(right[i+1]==-1) continue;
				else
				{
					int ri=right[i+1]+1;
					if((ch[i]=='('&&ch[ri]==')')||(ch[i]=='['&&ch[ri]==']'))
					{
						if(right[ri+1]==-1)
						{
							right[i]=ri;
							num[i]=num[i+1]+(ch[i]=='['?1:0);
						}
						else
						{
							right[i]=right[ri+1];
							num[i]=num[i+1]+num[ri+1]+(ch[i]=='['?1:0);
						}
					}
				}
			}
		}
	}
	int opt=-1;
	int pl=-1,ri=-1;
	for(int i=0;i<N;i++)
	{
		if(opt<num[i])
		{
			pl=i;
			ri=right[pl];
			opt=num[i];
		}
	}
	if(opt==-1)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		printf("%d\n",opt);
		for(int i=pl;i<=ri;i++)
		{
			printf("%c",ch[i]);
		}
		printf("\n");
	}
	return 0;
}