#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
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
struct prpppp
{
    int a,b;
}s[1000005];
bool bi(struct prpppp x,struct prpppp y)
{
	return x.a>y.a;
}
int n,m,a[1000005],b[1000005],c[1000005],d[1000005];
void solve()
{
    cin>>n>>m;
    for(int i=0;i<=m+2;i++)a[i]=b[i]=c[i]=d[i]=0;
    for(int i=1;i<=m;i++)cin>>s[i].a>>s[i].b;
    sort(s+1,s+m+1,bi);
    for(int i=1;i<=m;i++)a[i]=s[i].a, b[i]=s[i].b, d[i]=-a[i];
    for(int i=1;i<=m;i++)c[i]=c[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int pos=lower_bound(d+1,d+m+1,-b[i])-d-1;
        pos=min(pos,n-1);
        if(i<=pos && pos<n-1 && pos<m && a[pos+1]>b[i]) ++pos;
        int tmp=c[pos],fg=0;
        if(i<=pos)tmp-=a[i],fg=1;
        tmp+=a[i]+b[i]*(n-1-pos+fg);
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}
signed main()
{
    int t;
    t=read();
    while(t--) solve();
}