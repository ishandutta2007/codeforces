#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=__gcd(read(),read());
	int cnt=0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a[++cnt]=i;
			if(i*i!=n) a[++cnt]=n/i;
		}
	}
	sort(a+1,a+cnt+1);
	int m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if(u>n)
		{
			printf("%d\n",-1);continue;
		}
		int l=1,r=cnt,ans;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[mid]<=v) l=mid+1,ans=mid;
			else r=mid-1;
		}
		if(a[ans]>=u) printf("%d\n",a[ans]);
		else printf("%d\n",-1);
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}