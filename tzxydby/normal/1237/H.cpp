#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int n,st[N],tp,c1[4],c2[4],fl;
char s[N],t[N];
void rev(int x)
{
	if(!x)
		return;
	st[++tp]=x;
	reverse(s+1,s+x+1);
}
void sol()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	tp=fl=0;
	for(int i=1;i<=n;i++)
		s[i]-='0',t[i]-='0';
	for(int i=0;i<4;i++)
		c1[i]=c2[i]=0;
	for(int i=2;i<=n;i+=2)
		c1[s[i-1]<<1|s[i]]++,c2[t[i-1]<<1|t[i]]++;
	if(c1[0]!=c2[0]||c1[3]!=c2[3])
	{
		puts("-1");
		return;
	}
	int t1=c1[1]-c1[2],t2=c2[1]-c2[2];
	if(abs(t1)<abs(t2))
	{
		swap(s,t);
		fl=1;
	}
	if(t1!=-t2)
	{
		for(int i=2,r=0;i<=n;i+=2)
		{
			if((s[i-1]<<1|s[i])==1)
				r++;
			if((s[i-1]<<1|s[i])==2)
				r--;
			if(t1-r*2==-t2)
			{
				rev(i);
				break;
			}
		}
	}
	for(int i=2;i<=n;i+=2)
	{
		for(int j=i;j<=n;j+=2)
		{
			if(s[j]==t[n-i+1]&&s[j-1]==t[n-i+2])
			{
				rev(j-2);
				rev(j);
				break;
			}
		}
	}
	if(fl)
		reverse(st+1,st+tp+1);
	printf("%d\n",tp);
	for(int i=1;i<=tp;i++)
		printf("%d ",st[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}