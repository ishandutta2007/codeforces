#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[200005],p[200005];
int maxx[26][200005],lg2[200005];
ll ans;
int ask(int l,int r)
{
	int d=lg2[r-l+1];
	return a[maxx[d][l]]>a[maxx[d][r-(1<<d)+1]]?maxx[d][l]:maxx[d][r-(1<<d)+1];
}
void solve(int l,int r)
{
	if(r-l+1<3)return;
	int pos=ask(l,r);
	solve(l,pos-1);
	solve(pos+1,r);
	if(pos-l<r-pos)
	{
		for(int i=l;i<pos;i++)
		  if(p[a[pos]-a[i]]>pos&&p[a[pos]-a[i]]<=r)
		    ans++;
	}
	else
	{
		for(int i=pos+1;i<=r;i++)
		  if(p[a[pos]-a[i]]>=l&&p[a[pos]-a[i]]<pos)
		    ans++;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
		maxx[0][i]=i;
	}
	for(int i=2;i<=n;i++)
	  lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=lg2[n];i++)
	  for(int j=1;j<=n;j++)
	    maxx[i][j]=a[maxx[i-1][j]]>a[maxx[i-1][j+(1<<(i-1))]]?maxx[i-1][j]:maxx[i-1][j+(1<<(i-1))];
	solve(1,n);
	printf("%I64d\n",ans);
	return 0;
}