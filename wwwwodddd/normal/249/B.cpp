#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char s[500020];
int a[500020],ac;
int n,T,q,fh;
int ok(int x)
{
	int c=x,ti=0,nd=0,bk=0,md=0,fr=fh;
	if(x+ac<q)
		return 0;
	if(x<q)
		fr=max(fr,a[q-x-1]);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='S')
		{
			c++;
			if(nd!=0)
			{
				if(c>=nd)
				{
					c-=nd;
					if(ti+fr-i+fr-bk<=T)
						return 1;
					ti+=2*(i-bk);
					md+=nd;
					nd=0;
					if(ti>T)
						break;
				}
			}
		}
		else if(s[i]=='H')
		{
			if(c)
				c--,md++;
			else
			{
				if(nd==0)
				{
					nd++;
					bk=i;
				}
				else
					nd++;
			}
		}
		if(md==q)
			break;
		ti++;
	}
	if(nd)
		return 0;
	return ti<=T;
}
int main()
{
	cin>>n>>T,T--;
	scanf("%s",s);
	for(int i=0;i<n;i++)
		if(s[i]=='H')
			q++,fh=max(fh,i);
		else if(s[i]=='S')
			a[ac++]=i;
	int l=0,r=n+5; 
	while(l<r)
	{
		int m=l+r>>1;
		if(ok(m))
			r=m;
		else
			l=m+1;
	}
	if(l==n+5)
		cout << -1 << endl;
	else
		cout << l << endl;
	return 0;
}