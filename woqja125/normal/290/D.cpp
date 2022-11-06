#include<stdio.h>
char a[1001];
int main()
{
	int n;
	scanf("%s %d",a, &n);
	for(int i=0; a[i]!=0; i++)
	{
		if(a[i]<='Z') a[i]=a[i]-'A'+'a';
		if(a[i]<n+97)
		{
			printf("%c", a[i]-'a'+'A');
		}
		else
		{
			printf("%c", a[i]);
		}
	}
}