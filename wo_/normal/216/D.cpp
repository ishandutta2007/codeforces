#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct BIT{
	int N;
	int bit[100200];
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
	int sum(int i)
	{
		int res=0;
		while(i>=1)
		{
			res+=bit[i];
			i-=(i&(-i));
		}
		return res;
	}
	int sum()
	{
		return sum(N);
	}
};

BIT bit1,bit2;

vector<int> webs[1010];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int in;
			scanf("%d",&in);
			webs[i].push_back(in);
		}
		sort(webs[i].begin(),webs[i].end());
	}
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		if(i==0)
		{
			//1,N-1
			bit1.init(100100);
			bit2.init(100100);
			for(int j=0;j<webs[1].size();j++)
			{
				bit1.add(webs[1][j],1);
			}
			for(int j=0;j<webs[N-1].size();j++)
			{
				bit2.add(webs[N-1][j],1);
			}
			for(int j=0;j<(int)webs[0].size()-1;j++)
			{
				int c1=bit1.sum(webs[0][j+1])-bit1.sum(webs[0][j]);
				int c2=bit2.sum(webs[0][j+1])-bit2.sum(webs[0][j]);
				if(c1!=c2) cnt++;
			}
			continue;
		}
		bit1.init(100100);bit2.init(100100);
		for(int j=0;j<webs[i-1].size();j++)
		{
			bit1.add(webs[i-1][j],1);
		}
		for(int j=0;j<webs[(i+1)%N].size();j++)
		{
			bit2.add(webs[(i+1)%N][j],1);
		}
		for(int j=0;j<(int)webs[i].size()-1;j++)
		{
			int c1=bit1.sum(webs[i][j+1])-bit1.sum(webs[i][j]);
			int c2=bit2.sum(webs[i][j+1])-bit2.sum(webs[i][j]);
			if(c1!=c2) cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}