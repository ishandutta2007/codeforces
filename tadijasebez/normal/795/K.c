#include <stdio.h>
char a[100000];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",&a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='a')
		{
			if((i>0 && a[i-1]!='a') || i==0) printf("a");
		}
		else if(a[i]=='i')
		{
			if((i>0 && a[i-1]!='i') || i==0) printf("i");
		}
		else if(a[i]=='u')
		{
			if((i>0 && a[i-1]!='u') || i==0) printf("u");
		}
		else if(a[i]=='y')
		{
			if((i>0 && a[i-1]!='y') || i==0) printf("y");
		}
		else if(a[i]=='e')
		{
			if((i>0 && a[i-1]!='e' && a[i+1]=='e' && a[i+2]!='e') || (i==0 && a[i+1]=='e' && a[i+2]!='e')) printf("ee");
			else if((i>0 && a[i-1]!='e') || i==0) printf("e");
		}
		else if(a[i]=='o')
		{
			if((i>0 && a[i-1]!='o' && a[i+1]=='o' && a[i+2]!='o') || (i==0 && a[i+1]=='o' && a[i+2]!='o')) printf("oo");
			else if((i>0 && a[i-1]!='o') || i==0) printf("o");
		}
		else printf("%c",a[i]);
	}
	return 0;
}