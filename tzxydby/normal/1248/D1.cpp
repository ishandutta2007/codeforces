#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n;
char s[N];
int prer[N],preu[N],sufr[N],sufu[N];
struct X
{
	int v,l,r;
	bool operator>(const X x)const
	{
		return v>x.v;
	}
}as,now;
int check()
{
	int res,un;
	res=un=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
			res++;
		if(s[i]==')')
		{
			if(res)
				res--;
			else
				un++;
		}
		prer[i]=res;
		preu[i]=un;
	}
	res=un=0;
	for(int i=n;i>=1;i--)
	{
		if(s[i]==')')
			res++;
		if(s[i]=='(')
		{
			if(res)
				res--;
			else
				un++;
		}
		sufr[i]=res;
		sufu[i]=un;
	}
	int ans=0;
	if(prer[n]==0&&preu[n]==0)
		ans++;
	for(int i=2;i<=n;i++)
	{
		if(prer[i-1]>0)
			continue;
		if(sufr[i]>0)
			continue;
		if(preu[i-1]==sufu[i])
			ans++;
	} 
	return ans;
}
int main()
{
	scanf("%d%s",&n,s+1);
	as.v=check(),as.l=as.r=1;
	for(int l=1;l<=n;l++)
	{
		for(int r=1;r<=n;r++)
		{
			now.l=l;
			now.r=r;
			swap(s[l],s[r]);
			now.v=check();
			if(now>as)
				as=now;
			swap(s[l],s[r]);
		}
	}
	printf("%d\n%d %d\n",as.v,as.l,as.r);
	return 0;
}