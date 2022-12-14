#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char ch[12];
	scanf("%s",ch);
	int n=strlen(ch);
	for(int i=25;i>=0;i--)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(ch[j]=='a'+i)
			{
				cnt++;
			}
		}
		if(cnt!=0)
		{
			for(int j=0;j<cnt;j++)
			{
				printf("%c",'a'+i);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}