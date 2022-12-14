#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

struct BIT{
	int N;
	long long dat[200200];
	void init(int N_)
	{
		N=N_;
		for(int i=1;i<=N;i++) dat[i]=0;
	}
	void add(int i,long long x)
	{
		while(i<=N)
		{
			dat[i]+=x;
			i+=(i&(-i));
		}
	}
	void add(int i)
	{
		add(i,1);
	}
	long long sum(int i)
	{
		long long res=0;
		while(i>0)
		{
			res+=dat[i];
			i-=(i&(-i));
		}
		return res;
	}
};

BIT bit;

int p[200200],ids[200200];

vector<int> divs[200200];

vector<P> ls[200200];//[r]=(l,id)
long long ans[200200];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=2;i*j<=N;j++)
		{
			divs[i*j].push_back(i);
		}
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%d",p+i);
		ids[p[i]]=i;
	}
	for(int i=0;i<M;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ls[r].push_back(P(l,i));
	}
	bit.init(N);
	for(int i=1;i<=N;i++)
	{
		int num=p[i];
		for(int j=0;j<divs[num].size();j++)
		{
			int a=divs[num][j];
			int id=ids[a];
			if(i<id) continue;
			bit.add(id);
		}
		for(int j=2;num*j<=N;j++)
		{
			int a=num*j;
			int id=ids[a];
			if(i<id) continue;
			bit.add(id);
		}
		for(int j=0;j<ls[i].size();j++)
		{
			int l=ls[i][j].first;
			ans[ls[i][j].second]=bit.sum(i)-bit.sum(l-1)+i-l+1;
		}
	}
	for(int i=0;i<M;i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}