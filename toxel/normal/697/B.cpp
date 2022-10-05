#include<bits/stdc++.h>
const int N=1000;
int main()
{
	char s[N],a[N],d[N];
	int i=0,j=0,b=0;
	scanf("%s",s);
	while (s[i]!='.')
		a[j++]=s[i++];
	a[j]=0;
	i++;
	j=0;
	while (s[i]!='e')
		d[j++]=s[i++];
	d[j]=0;
	i++;
	while (s[i]!=0)
		b=b*10+s[i++]-'0';
	if (strcmp(d,"0")==0)
	{
		printf("%s",a);
		for (i=0;i<b;i++)
			printf("0");
		return 0;
	}
	if (strlen(d)<=b)
	{
		printf("%s%s",a,d);
		for (i=0;i<b-strlen(d);i++)
			printf("0");
		return 0;
	}
	if (b==0)
	{
		printf("%s.%s",a,d);
		return 0;
	}
	printf("%s",a);
	for (i=0;i<b;i++)
		printf("%c",d[i]);
	printf(".");
	for (;i<strlen(d);i++)
		printf("%c",d[i]);
	return 0;
}