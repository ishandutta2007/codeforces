#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

long long c[1010][1010];

long long rows[1010],cols[1010];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	long long row=1ll<<62,col=1ll<<62;
	for(int j=0;j<M;j++)
	{
		rows[j]=0;
		for(int i=0;i<N;i++)
		{
			rows[j]+=c[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		cols[i]=0;
		for(int j=0;j<M;j++)
		{
			cols[i]+=c[i][j];
		}
	}
	int bstr=1<<30,bstc=1<<30;
	for(int i=0;i<=M;i++)
	{
		long long tmp=0;
		for(int j=0;j<M;j++)
		{
			int ii=2*i,jj=2*j+1;
			int t=abs(ii-jj);
			tmp+=(long long)t*t*rows[j];
		}
		if(row>tmp)
		{
			row=tmp;
			bstc=i;
		}
	}
	for(int i=0;i<=N;i++)
	{
		long long tmp=0;
		for(int j=0;j<N;j++)
		{
			int ii=2*i,jj=2*j+1;
			int t=abs(ii-jj);
			tmp+=(long long)t*t*cols[j];
		}
		if(col>tmp)
		{
			col=tmp;
			bstr=i;
		}
	}
	cout<<(row+col)*4<<"\n";
	cout<<bstr<<" "<<bstc<<"\n";
	return 0;
}