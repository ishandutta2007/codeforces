#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005];
int n,stx[200005],sty[200005],enx[200005],eny[200005];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		int d=abs(enx[i]-stx[max(i-x,0)])+abs(eny[i]-sty[max(i-x,0)]);
		if(d<=x&&(x-d)%2==0)return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d%d",&enx[n],&eny[n]);
	if(abs(enx[n])+abs(eny[n])>n)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		stx[i]=stx[i-1];
		sty[i]=sty[i-1];
		if(s[i]=='U')sty[i]++;
		if(s[i]=='D')sty[i]--;
		if(s[i]=='L')stx[i]--;
		if(s[i]=='R')stx[i]++;
	}
	for(int i=n-1;i>=0;i--)
	{
		enx[i]=enx[i+1];
		eny[i]=eny[i+1];
		if(s[i+1]=='U')eny[i]--;
		if(s[i+1]=='D')eny[i]++;
		if(s[i+1]=='L')enx[i]++;
		if(s[i+1]=='R')enx[i]--;
	}
	if(abs(enx[0]-stx[0])+abs(eny[0]-sty[0])&1)
	{
		printf("-1\n");
		return 0;
	}
	int l=0,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}