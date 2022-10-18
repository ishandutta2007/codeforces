#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
	ll pl;
	ll data;
};
Node a[400005];
ll ans[200005];
bool cmp(Node x,Node y)
{
	return x.pl<y.pl;
}
int main()
{
	int n;
	cin>>n;
	ll u,v;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d %I64d",&u,&v);
		a[i*2-1].pl=u;
		a[i*2].pl=v+1;
		a[i*2-1].data=1;
		a[i*2].data=-1;
	}
	sort(a+1,a+2*n+1,cmp);
	ll lst=0;
	ll tmp=0;
	for(int i=1;i<=n*2;i++)
	{
		ll to=a[i].pl-lst;
		ans[tmp]+=to;
		tmp+=a[i].data;
		lst=a[i].pl;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	return 0;
}
// REJUDGE