#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],b[N],c[N],k;
int n;
priority_queue<pair<double,int>>pq;
int check(long long x)
{
	while(!pq.empty())
		pq.pop();
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i];
		pq.push(make_pair(-(double)c[i]/b[i],i));
	}
	for(int i=1;i<=k;i++)
	{
		int u=pq.top().second;
		pq.pop();
		if((i-1)*b[u]>c[u])
			return 0;
		c[u]+=x;
		pq.push(make_pair(-(double)c[u]/b[u],u));
	}
	for(int i=1;i<=n;i++)
		if(k*b[i]>c[i])
			return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	k--;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	long long l=-1,r=2e12;
	while(r-l>1)
	{
		long long mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid; 
	}
	cout<<(r==2e12?-1:r)<<endl;
	return 0;
}