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
int p[200005],minl[200005],maxr[200005];
int qmaxl[200005],qmaxr[200005],hmaxl[200005],hmaxr[200005];
int main()
{
	int n,x,y;
	n=read();
	for(int i=1;i<=n;i++)p[i]=read();
	minl[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(p[i-1]<p[i])minl[i]=minl[i-1];
		else minl[i]=i;
	}
	maxr[n]=n;
	for(int i=n-1;i>=1;i--)
	{
		if(p[i]>p[i+1])maxr[i]=maxr[i+1];
		else maxr[i]=i;
	}
	qmaxl[1]=1-minl[1]+1;
	for(int i=2;i<=n;i++)qmaxl[i]=max(qmaxl[i-1],i-minl[i]+1);
	for(int i=1;i<=n;i++)qmaxr[maxr[i]]=max(qmaxr[maxr[i]],maxr[i]-i+1);
	qmaxr[1]=1;
	for(int i=2;i<=n;i++)qmaxr[i]=max(qmaxr[i-1],qmaxr[i]);
	hmaxr[n]=maxr[n]-n+1;
	for(int i=1;i<=n;i++)hmaxl[minl[i]]=max(hmaxl[minl[i]],i-minl[i]+1);
	hmaxl[n]=1;
	for(int i=n-1;i>=1;i--)hmaxl[i]=max(hmaxl[i+1],hmaxl[i]);
	for(int i=n-1;i>=1;i--)hmaxr[i]=max(hmaxr[i+1],maxr[i]-i+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		x=i-minl[i]+1;
		y=maxr[i]-i+1;
		if(p[i-1]>p[i]||p[i+1]>p[i])continue;
		if(y==x&&y%2==0)continue;
		if(x>y||y>x)continue;
		if(qmaxl[minl[i]]>=max(x,y))continue;
		if(qmaxr[minl[i]]>=max(x,y))continue;
		if(hmaxr[maxr[i]]>=max(x,y))continue;
		if(hmaxl[maxr[i]]>=max(x,y))continue;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}