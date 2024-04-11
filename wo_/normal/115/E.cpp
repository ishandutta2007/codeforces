#include<cstdio>
#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>

using namespace std;

const int inf=1<<28;

typedef pair<int,long long> P;

struct RMQ{
	int N;
	long long dat[524288];
	long long umax[524288];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=N*2-1;i++) dat[i]=0;
		for(int i=0;i<=N*2-1;i++) umax[i]=0;
	}
	void update(int l,int r,long long x,int k,int a,int b)
	{
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r)
		{
			dat[k]+=x;
			umax[k]+=x;
			return;
		}
		update(l,r,x,k*2,a,(a+b)/2);
		update(l,r,x,k*2+1,(a+b)/2,b);
		umax[k]=max(umax[k*2],umax[k*2+1])+dat[k];
	}
	void update(int l,int r,long long x)
	{
		update(l,r,x,1,0,N);
	}
	long long get()
	{
		return umax[1];
	}
};

RMQ dp;

vector<P> prev[200200];

int repair_cost[200200];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	dp.init(N+1);
	for(int i=0;i<N;i++) scanf("%d",repair_cost+i);
	for(int i=0;i<M;i++)
	{
		int lb,ub,p;
		scanf("%d%d%d",&lb,&ub,&p);
		lb--;ub--;
		prev[ub].push_back(P(lb,p));
	}
	for(int i=0;i<N;i++)
	{
		//i->i+1;
		int st=N-i-1;
		long long prev_maxprofit=dp.get();
		dp.update(st,st+1,prev_maxprofit);/*
		long long increaseprofit=-repair_cost[i];
		sort(prev[i].begin(),prev[i].end());
		reverse(prev[i].begin(),prev[i].end());
		int updated=N;
		for(int j=0;j<prev[i].size();j++)
		{
			if(prev[i][j].first!=updated)
			{
				int l=prev[i][j].first+1+st;
				dp.update(l,updated+1,increaseprofit);
			}
			updated=prev[i][j].first+st;
			increaseprofit+=prev[i][j].second;
		}
		if(st+1<updated+1) dp.update(st+1,updated+1,increaseprofit);
		printf("%d %lld\n",i,increaseprofit);*/
		dp.update(st+1,N+1,-repair_cost[i]);
		for(int j=0;j<prev[i].size();j++)
		{
			int dis=i-prev[i][j].first;
			dp.update(st+dis+1,N+1,prev[i][j].second);
		}
	}
	cout<<dp.get()<<"\n";
	return 0;
}