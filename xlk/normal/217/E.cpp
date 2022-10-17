#include<stdio.h>
char s[3000020],*ss=s,z[3000020];
int c[3000020],f[3000020];
int w,n,k,p,x[5020],y[5020];
void R(int x)
{
	for(w--;x<=k;x+=x&-x)
		c[x]--;
}
int A(int x)
{
	int _=0;
	for(int i=1<<21;i;i>>=1)
		if(_+i<=k&&x>c[_+i])
			x-=c[_+=i];
	return _+1;
}
int main()
{
	scanf("%s",s+1);
	scanf("%d %d",&k,&n),w=k;
	for(int i=0;i<n;i++)
		scanf("%d %d",x+i,y+i),y[i]++;
	for(int i=1;i<=k;i++)
		c[i]=i&-i;
	for(int i=n;i--;)
		for(int j=0,u=x[i]+1;j<y[i]-x[i]&&y[i]<=w;j++,u+=2)
		{
			if(u>=y[i])
				u=x[i];
			R(p=A(y[i])),f[p]=A(u);
		}
	for(int i=1;i<=k;i++)
		z[i]=f[i]?z[f[i]]:*++ss;
	puts(z+1);
	return 0;
}