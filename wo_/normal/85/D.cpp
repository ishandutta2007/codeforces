#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct node{
	int num;
	long long sum[5];
	node(){}
};

vector<int> vals;

struct segtree{
	int N;
	node nodes[270270];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
	}
	void query(int i,bool flg)
	{
		i+=N;
		if(flg)
		{
			nodes[i].num=1;
			nodes[i].sum[0]=vals[i-N];
		}
		else
		{
			nodes[i].num=0;
			nodes[i].sum[0]=0;
		}
		while(i>1)
		{
			i/=2;
			nodes[i].num=nodes[i*2].num+nodes[i*2+1].num;
			for(int r=0;r<5;r++)
			{
				nodes[i].sum[r]=nodes[i*2].sum[r];
			}
			for(int r=0;r<5;r++)
			{
				nodes[i].sum[(r+nodes[i*2].num)%5]+=nodes[i*2+1].sum[r];
			}
		}
	}
	long long get()
	{
		return nodes[1].sum[2];
	}
};

segtree seg;

char ch[100100][10];
int val[100100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",&ch[i]);
		if(ch[i][0]=='s') continue;
		else scanf("%d",val+i);
		vals.push_back(val[i]);
	}
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	seg.init(vals.size());
	for(int i=0;i<N;i++)
	{
		if(ch[i][0]=='s')
		{
			cout<<seg.get()<<"\n";
			continue;
		}
		int id=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),val[i]));
		if(ch[i][0]=='a') seg.query(id,true);
		else seg.query(id,false);
	}
	return 0;
}