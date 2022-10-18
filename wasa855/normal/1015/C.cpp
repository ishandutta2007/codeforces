#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
struct Node
{
	ll x;
	ll y;
};
Node a[100005];
bool cmp(Node x,Node y)
{
	return (x.x-x.y)>(y.x-y.y);
}
int main()
{
	cin>>n>>m;
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a[i].x,&a[i].y);
		tot+=a[i].x;
	}
	sort(a+1,a+n+1,cmp);
	int i=1;
	while(tot>m&&i<=n)
	{
		tot-=(a[i].x-a[i].y);
		i++;
	}
	if(i==n+1&&tot>m)
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<i-1<<endl;
	}
	return 0;
}