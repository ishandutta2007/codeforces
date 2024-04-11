#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rel[100100];
long long sum[100100];
int sumid[100100];

struct BIT{
	int N;
	long long bit[100100];
	void init(int N_)
	{
		N=N_;
		for(int i=0;i<=N;i++) bit[i]=0;
	}
	void add(int i,int x)
	{
		while(i<=N)
		{
			bit[i]+=x;
			i+=(i&(-i));
		}
	}
	long long sum(int i)
	{
		long long res=0;
		if(i>N) return sum();
		while(i>=1)
		{
			res+=bit[i];
			i-=(i&(-i));
		}
		return res;
	}
	long long sum()
	{
		return sum(N);
	}
};

BIT bit;

vector<long long> vals;

int main()
{
	int N;
	long long K;
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		scanf("%d",rel+i+1);
	}
	sum[0]=0;
	vals.push_back(0);
	for(int i=1;i<=N;i++)
	{
		sum[i]=sum[i-1]+rel[i];
		vals.push_back(sum[i]);
	}
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	for(int i=0;i<=N;i++)
	{
		sumid[i]=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),sum[i]))+1;
	}
	long long lb=-(1ll<<50),ub=1ll<<50;
	while(ub-lb>1)
	{
		//[lb,ub)
		long long mid=(ub+lb)/2;
		bit.init(vals.size()+1);
		bit.add(sumid[N],1);
		long long cnt=0;
		for(int i=N-1;i>=0;i--)
		{
			long long bnd=vals[sumid[i]-1]+mid;
			int id=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),bnd))+1;
			id--;
			cnt+=(bit.sum()-bit.sum(id));
			bit.add(sumid[i],1);
		}
		if(cnt>=K)
		{
			lb=mid;
		}
		else ub=mid;
	}
	cout<<lb<<"\n";
	return 0;
}