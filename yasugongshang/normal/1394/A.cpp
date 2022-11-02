#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,a[100005],sum[100005],ans,b[100005],res;
inline int cmp(int x,int y){return x>y;}
signed main()
{
	cin>>n>>d>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x>m)a[++a[0]]=x;
		else b[++b[0]]=x;
	}
	sort(a+1,a+a[0]+1,cmp);
	sort(b+1,b+b[0]+1,cmp);
	for(int i=1;i<=b[0];i++)sum[i]=sum[i-1]+b[i];
	for(int i=1;i<=a[0];i++)
	{
		ans+=a[i];
		int k=(d+1)*(i-1)+1;
		if(k>n)break;
		res=max(res,ans+sum[min(b[0],n-k)]);
	}
	printf("%lld",max(sum[b[0]],res));
}