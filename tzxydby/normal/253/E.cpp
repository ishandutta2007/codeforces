#include<bits/stdc++.h>
using namespace std;
const int N=50005;
struct task
{
	int time,pri,pages,id;
	bool operator<(const task x)
	{
		return time==x.time?pri>x.pri:time<x.time;
	}
}a[N];
int n,miss,res[N];
long long et[N],t;
set<int>sp;
vector<int>p;
void check(int mp)
{
	priority_queue<pair<int,int>>pq;
	a[miss].pri=mp;
	for(int i=0;i<n;i++)
		res[i]=a[i].pages;
	for(int i=0;i<n;i++)
	{
		int tt=i?a[i-1].time:0;
		while(!pq.empty()&&tt<a[i].time)
		{
			int k=pq.top().second,cost=min(res[k],a[i].time-tt);
			res[k]-=cost;
			tt+=cost;
			if(!res[k])
			{
				pq.pop();
				et[a[k].id]=tt;
			}
		}
		pq.push(make_pair(a[i].pri,i));
	}
	long long tt=a[n-1].time;
	while(!pq.empty())
	{
		int k=pq.top().second;
		tt+=res[k];
		et[a[k].id]=tt;
		pq.pop();
	}
	
}
int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].time>>a[i].pages>>a[i].pri;
		a[i].id=i;
		sp.insert(a[i].pri);
	}
	cin>>t;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i].pri==-1)
			miss=i;
		else
		{
			if(a[i].pri>1&&!sp.count(a[i].pri-1))
				p.push_back(a[i].pri-1);
			if(!sp.count(a[i].pri+1))
				p.push_back(a[i].pri+1);
		}
	}
	sort(p.begin(),p.end());
	int lb=0,ub=p.size()-1,ans;
	while(lb<=ub)
	{
		int mid=(lb+ub)>>1;
		check(p[mid]);
		if(et[a[miss].id]==t)
		{
			ans=p[mid];
			break;
		}
		if(et[a[miss].id]>t)
			lb=mid+1;
		else
			ub=mid-1;
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
		cout<<et[i]<<' ';
	cout<<endl; 
	return 0;
}