#include <cstdio>
#include <cstring>

int abs(int x)
{
	if(x>=0) return x;
	else return -x;
}

char str[100100];

int u=0,r=0,d=0,l=0;

int main()
{
	scanf(" %s", str);
	if(strlen(str)%2!=0) printf("-1");
	else
	{
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]=='U')u++;
			else if(str[i]=='R')r++;
			else if(str[i]=='D')d++;
			else if(str[i]=='L')l++;
		}
		printf("%i",(abs((u-d)/2)+(u+d)%2+abs((l-r)/2)));
		/*if(u<d)
		{
			int a=u;u=d;d=a;
		}
		if(r<l)
		{
			int a=r;r=l;l=a;
		}*/

	}
}