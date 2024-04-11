#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int maxl[200005],maxr[200005],minl[200005],minr[200005],het[200005];
char s[200005];
int main()
{
	int t,n,q,x,y,tl,tr;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		scanf("%s",s+1);
		maxl[0]=0;
		minl[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='+')het[i]=het[i-1]+1;
			else het[i]=het[i-1]-1;
			maxl[i]=max(maxl[i-1],het[i]);
			minl[i]=min(minl[i-1],het[i]);
		}
		minr[n+1]=1000000000;
		maxr[n+1]=-1000000000;
		for(int i=n;i>=1;i--)maxr[i]=max(maxr[i+1],het[i]);
		for(int i=n;i>=1;i--)minr[i]=min(minr[i+1],het[i]);
		for(int i=1;i<=q;i++)
		{
			tl=read();
			tr=read();
			x=minl[tl-1];
			y=maxl[tl-1];
			if(tr!=n)x=min(x,minr[tr+1]-het[tr]+het[tl-1]);
			if(tr!=n)y=max(y,maxr[tr+1]-het[tr]+het[tl-1]);
			printf("%d\n",y-x+1);
		}
	}
	return 0;
}