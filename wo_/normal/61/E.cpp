#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct BIT{
	int N;
	long long bit[1000100];
	void init(int N_)
	{
		N=N_;
		for(int i=0;i<=N;i++)
		{
			bit[i]=0;
		}
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

BIT bit1,bit2;

vector<int> vals;
int a[1000100];
int ca[1000100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
		vals.push_back(a[i]);
	}
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	for(int i=0;i<N;i++)
	{
		ca[i]=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),a[i]));
		ca[i]++;
	}
	bit1.init(vals.size()+1);bit2.init(vals.size()+1);
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		long long m=bit1.sum()-bit1.sum(ca[i]);
		long long l=bit2.sum()-bit2.sum(ca[i]);
		ans+=l;
		bit1.add(ca[i],1);
		bit2.add(ca[i],m);
	}
	cout<<ans<<"\n";
	return 0;
}