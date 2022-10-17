#include<stdio.h>
#define fo(i,n) for(int i=1;i<=n;i++)
int n,m;
char s[1020][1020],z[1020][1020];
int main()
{
	scanf("%d%d",&n,&m);
	fo(i,n)
		scanf("%s",s[i]+1);
	fo(i,n)
		fo(j,m)
			z[i][j]='.';
	fo(i,n)
		fo(j,m)
			if(s[i][j]=='b')
			{
				char c='a'+(i+j/2*2)%4;
				if(s[i-1][j]=='w'&&s[i+1][j]=='w')
					s[i-1][j]=s[i+1][j]=s[i][j]='.',z[i-1][j]=z[i+1][j]=z[i][j]=c;
				else if(s[i][j-1]=='w'&&s[i][j+1]=='w') 
					s[i][j-1]=s[i][j+1]=s[i][j]='.',z[i][j-1]=z[i][j+1]=z[i][j]=c;
			}
	fo(i,n)
		fo(j,m)
			if(s[i][j]=='b'||s[i][j]=='w')
				return puts("NO"),0;
	puts("YES");
	fo(i,n)
		puts(z[i]+1);
}