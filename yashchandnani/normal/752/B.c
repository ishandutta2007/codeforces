#include <stdio.h>
int main()
{
	char s[1001],t[1001];
	scanf("%s%s",s,t);
	
	int flag[26],a[1001],b[1001];
	for (int i = 0; s[i]!='\0'; ++i)
	{
		a[i] = (int)s[i] - 97 ;
		b[i] = (int)t[i] - 97 ;
	}
	
	for (int i = 0; i < 26; ++i)
	{
		flag[i]=0;
	}
	int rep[26];
	char c[26],d[26];
	int count=0,j=0;
	for (int i = 0; s[i]!='\0'; ++i)
	{
		if((flag[a[i]]==0)&&(flag[b[i]]==0)){
			flag[a[i]]=1;
			flag[b[i]]=1;
			rep[a[i]] =b[i];
			rep[b[i]] =a[i];
			if (a[i]!=b[i])
				{
					c[j]=a[i]+97;
						d[j]=b[i]+97;
						count++;
						j++;
				}
			
			continue;
		}
		else if((flag[a[i]]!=0)&&(flag[b[i]]!=0)){
			if ((rep[a[i]]==b[i])&&(rep[b[i]]==a[i]))
			{
				continue;
			}
		}
		printf("-1");
		return 0;
	}
	
	printf("%d\n",count );
	for (int i = 0; i < count; ++i)
	{	
		printf("%c %c\n",c[i],d[i] );	}
	return 0;
}