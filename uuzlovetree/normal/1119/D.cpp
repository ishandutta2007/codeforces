#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std; 
int n,q;
ll s[maxn];
priority_queue<ll,vector<ll>,greater<ll>> pq;
pair<ll,int> qry[maxn];
ll qry2[maxn]; 
map<ll,ll> Ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&s[i]);
	sort(s+1,s+n+1);
	for(int i=1;i<n;++i)pq.push(s[i+1]-s[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		ll l,r;
		scanf("%I64d%I64d",&l,&r);
		qry[i]=make_pair(r-l,i);
		qry2[i]=r-l;
	}
	sort(qry+1,qry+q+1);
	int d=unique(qry+1,qry+q+1)-qry-1;
	ll last=0;
	ll res=0,num=n;
	while(!pq.empty()&&pq.top()==0)pq.pop(),num--;
	for(int i=1;i<=d;++i)
	{
		ll k=qry[i].first;
		int id=qry[i].second;
		while(!pq.empty()&&pq.top()<=k)
		{
			ll x=pq.top();pq.pop();
			if(x!=last)
			{
				res+=(x-last)*num;
				num--;last=x;
			}
			else
			{
				num--;
			}
		}
		res+=(k+1-last)*num;last=k+1;
		Ans[k]=res;
	}
	for(int i=1;i<=q;++i)
	{
		printf("%I64d ",Ans[qry2[i]]);
	}
	return 0;
}