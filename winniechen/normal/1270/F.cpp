#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005 , size = 1000;
char s[N]; int n , b[N],a[N],w[N];
struct node
{
	ll x,y;
	node(){x=y=0;}
	node(ll a, ll b){x=a,y=b;}
}c[N];
bool cmp(const node &a,const node &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int main()
{
	scanf("%s",s+1); n = strlen(s+1);
	for(int i=1;i<=n;i++)a[i]=(s[i]=='1');
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	w[b[n]+1]=n+1; ll ans = 0;
	for(int i=n;~i;i--)
	{
		if(a[i])w[b[i]]=i;
		for(int j=b[i]+1;j<=b[i]+size&&j<=b[n];j++)
			ans += (w[j+1]-1-i)/(j-b[i])-(w[j]-1-i)/(j-b[i]);
	}
	for(int x=1;x<=n/size;x++)
	{
		for(int j=0;j<=n;j++)
			c[j] = node(j-x*b[j],j);
		sort(c,c+n+1,cmp);
		for(int i=0,j=0;i<=n;i=j)
		{
			int k = i-1;
			for(j=i;c[j].x==c[i].x&&j<=n;j++)
			{
				for(;b[c[j].y]-b[c[k+1].y]>size;k++);
				ans += k-i+1;
			}
		}
	}
	printf("%lld\n",ans);
}