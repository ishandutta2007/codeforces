#include"stdio.h"
int main()
{
	char inp[1000];
	char a[10];
	a[0]='h';
	a[1]='e';
	a[2]='l';
	a[3]='l';
	a[4]='o';
	a[5]=0;
	scanf("%s",inp);
	int x=0,y=0;
	while(a[x] && inp[y])
	{
		if(a[x]==inp[y])
		{x++;
		}
		y++;
	}
	if(x==5)printf("YES");
	else printf("NO");
}