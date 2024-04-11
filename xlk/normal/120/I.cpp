#include<stdio.h>
#include<string.h>
int v[10]={119,36,93,109,46,107,123,37,127,111},n,l,u,c,x,d,y;
char s[200000];
int C(char a,char b)
{
	return __builtin_popcount(v[a]&v[b]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%s",s),l=strlen(s),n=l/2;
	for(int i=0;i<l;i++)
		s[i]-='0';
	for(int i=l;i--;)
	{
		c=s[i+(i<n?n:-n)],x=C(s[i],c);
		for(int j=s[i]+1;j<10;j++)
			if(u+C(j,c)>x)
			{
				s[i]=j;
				u+=C(j,c)-x;
				for(int k=i+1;k<l;k++)
				{
					d=s[k+(k<n?n:-n)];
					y=C(d,s[k]);
					for(int m=0;m<10;m++)
						if(u+C(m,d)>y)
						{
							s[k]=m;
							u+=C(m,d)-y;
							break;
						}
				}
				for(int k=0;k<l;k++)
					printf("%c",s[k]+'0');
				return 0;
			}
		s[i]=8;
		u+=C(s[i],c)-x;
	}
	puts("-1");
	return 0;
}