#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,r,d=1e9;
char s[N],ans[N];
void sol(int a,int b)
{ 
	int nd=0;
	s[0]=' ';
	for(int i=n;i>=1;i--)
	{
		if(a==0||b==0||nd>=d)
			return;
		if(a>=b)
		{
			s[i]='T';
			a-=b;
		}
		else
		{
			s[i]='B';
			b-=a;
		}
		nd+=(s[i]==s[i+1]);
	}
	if(a==0&&b==1&&s[1]=='T'&&nd<d)
	{
		d=nd;
		for(int i=1;i<=n;i++)
			ans[i]=s[i];	
	} 
}
int main()
{	
	scanf("%d%d",&n,&r);
	for(int i=0;i<=r;i++)
	{
		sol(i,r);
		sol(r,i);
	}
	if(d==1e9)
		puts("IMPOSSIBLE");
	else
	{	
		printf("%d\n",d);
		for(int i=1;i<=n;i++)
			printf("%c",ans[i]); 
	}
	return 0;
}