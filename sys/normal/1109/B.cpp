#include <bits/stdc++.h>
using namespace std;
char str[5005],tmp[5005];
char res;
map <int,int> Ma;
int main()
{
	scanf("%s",str);
	int siz=strlen(str);
	if(siz%2)
	{
		for(int i=0;i<siz;i++)
			if(i!=siz/2)
			{
				if(res!='\0'&&str[i]!=res)
				{
					printf("2");
					return 0;
				}
				else
					res=str[i];
			}
	}
	else
	{
		for(int i=0;i<siz;i++)
		{
			if(res!='\0'&&str[i]!=res)
			{
				goto A;
			}
			else
				res=str[i];
		}
	}
	printf("Impossible");
	return 0;
	A:
	memcpy(tmp,str,sizeof(tmp));
	for(int i=siz;(!(i%2))&&i>0;i>>=1)
	{
		reverse(str,str+(i>>1));
		if(strcmp(tmp,str))
		{
			printf("1");
			return 0;
		}
		reverse(str,str+(i>>1));
	}
	printf("2");
	return 0;
}