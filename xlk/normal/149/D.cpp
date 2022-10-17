#include<stdio.h>
#include<string.h>
int f[720][720][3][3];
int st[720],ss,n,p=1000000007;
int l[720];
char s[720];
int F(int x,int y,int l,int r)
{
	if(x>y)
		return 1;
	int &t=f[x][y][l][r];
	if(t>=0)
		return t;
	t=0;
	int q=::l[x];
	for(int i=1;i<3;i++)
	{
		if(q<y||i!=r)
			t=(t+(long long)F(x+1,q-1,0,i)*F(q+1,y,i,r))%p;
		if(i!=l)
			t=(t+(long long)F(x+1,q-1,i,0)*F(q+1,y,0,r))%p;
	}
	return t;
}
int main()
{
	memset(f,-1,sizeof f);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[i]=='(')
			st[ss++]=i;
		else
			l[st[--ss]]=i;
	printf("%d",F(0,n-1,0,0));
	return 0;
}