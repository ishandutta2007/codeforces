#include<bits/stdc++.h>
using namespace std;
 
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 100005
struct Node
{
	int s,g;
};
Node a[N];
int b[N];
int sum[N];
bool cmp(Node x,Node y)
{
	return x.s<y.s;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=m;i++) a[i].s=read(),a[i].g=read();
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+a[i].g;
	}
	for(int i=1;i<=n;i++)
	{
		int l=0,r=m,mid,ans;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[mid].s<=b[i])
			{
				l=mid+1,ans=mid;
			}
			else r=mid-1;
		}
		printf("%d ",sum[ans]);
	}
	return 0;
}
//sacef