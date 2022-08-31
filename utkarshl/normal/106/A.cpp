#include"stdio.h"
void find(char a1,char a2)
{
		bool b=false;
		char str[]="6789TJQKA";
		for(int x=0;a1!=str[x];x++)
		{
			if(a2==str[x])
{			printf("YES"),b=true;}
		}
		if(!b)printf("NO");
}
int main()
{
	char t[100],f[100],s[100];
	scanf("%s%s%s",t,f,s);
	if(f[1]!=t[0])
	{
		if(f[1]!=s[1])
			printf("NO");
		else
			find(f[0],s[0]);
	}
	else if(s[1]!=t[0])printf("YES");
	else 
	{
		find(f[0],s[0]);
	}
}