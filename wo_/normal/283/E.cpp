#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct segtree{
	int N;
	int dat[262144];
	int total[262144];
	bool flip[262144];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=N;i<=N*2-1;i++)
		{
			total[i]=1;
			dat[i]=0;
			flip[i]=false;
		}
		for(int i=N-1;i>=1;i--)
		{
			total[i]=total[i*2]+total[i*2+1];
			dat[i]=dat[i*2]+dat[i*2+1];
			flip[i]=false;
		}
	}
	void change(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r)
		{
			dat[k]=total[k]-dat[k];
			flip[k]=!flip[k];
			return;
		}
		else if(b<=l||r<=a) return;
		if(flip[k])
		{
			flip[k]=false;
			dat[k*2]=total[k*2]-dat[k*2];
			dat[k*2+1]=total[k*2+1]-dat[k*2+1];
			flip[k*2]=!flip[k*2];
			flip[k*2+1]=!flip[k*2+1];
		}
		change(l,r,k*2,a,(a+b)/2);
		change(l,r,k*2+1,(a+b)/2,b);
		dat[k]=dat[k*2]+dat[k*2+1];
	}
	void change(int l,int r)
	{
		change(l,r,1,0,N);
	}
	int get1(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r)
		{
			return dat[k];
		}
		else if(b<=l||r<=a) return 0;
		if(flip[k])
		{
			flip[k]=false;
			dat[k*2]=total[k*2]-dat[k*2];
			dat[k*2+1]=total[k*2+1]-dat[k*2+1];
			flip[k*2]=!flip[k*2];
			flip[k*2+1]=!flip[k*2+1];
		}
		return get1(l,r,k*2,a,(a+b)/2)+get1(l,r,k*2+1,(a+b)/2,b);
	}
	int get1(int l,int r)
	{
		return get1(l,r,1,0,N);
	}
};

segtree seg;

int ss[100100];
int ls[100100],rs[100100];
vector<int> ins[100100],outs[100100];

int wins[100100];

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	seg.init(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",ss+i);
	}
	sort(ss,ss+N);
	for(int i=0;i<K;i++)
	{
		scanf("%d%d",ls+i,rs+i);
		int lid=lower_bound(ss,ss+N,ls[i])-ss;
		int rid=upper_bound(ss,ss+N,rs[i])-ss;
		//[lid,rid)
		ins[lid].push_back(rid);
		outs[rid].push_back(lid);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<ins[i].size();j++)
		{
			int r=ins[i][j];
			seg.change(i,r);
		}
		for(int j=0;j<outs[i].size();j++)
		{
			int l=outs[i][j];
			seg.change(l,i);
		}
		int tmp=0;
		//weaker
		tmp+=(i-seg.get1(0,i));
		//stronger
		tmp+=seg.get1(i+1,N);
		wins[i]=tmp;
	}
	long long total=(long long)N*(N-1)*(N-2)/6;
	long long invalid=0;
	for(int i=0;i<N;i++)
	{
		invalid+=(long long)wins[i]*(wins[i]-1)/2;
	}
	cout<<total-invalid<<"\n";
	return 0;
}