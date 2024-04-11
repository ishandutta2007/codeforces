#include<stdio.h>
#include<string.h>
int f[4020],n,m;
char s[2020];
int main()
{
	scanf("%s",s);
	f[n=m=strlen(s)]=1;
	for(int i=0;i<n;i++)
		if(s[i]<48)
			if(s[i]=='+'||s[i]=='-'||i&&s[i-1]>='0')
				m--;
			else
				return puts("0"),0;
		else if(s[i+1]<'0')
			for(int j=m+n;j-->m;)
				f[j]=(f[j]+f[j+1])%1000003;
	printf("%d\n",f[m]);
}