#include<cstdio>
#include<iostream>

using namespace std;

struct segtree{
	int N;
	bool cov[262144];
	int dat[262144];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++) dat[i]=0;
		for(int i=1;i<=N*2-1;i++) cov[i]=false;
	}
	void setchild(int k,int len)
	{
		if(cov[k]==false) return;
		if(k>=N) return;
		cov[k]=false;
		cov[k*2]=!cov[k*2];
		cov[k*2+1]=!cov[k*2+1];
		dat[k*2]=len/2-dat[k*2];
		dat[k*2+1]=len/2-dat[k*2+1];
	}
	void change(int l,int r,int k,int a,int b)
	{
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r)
		{
			cov[k]=!cov[k];
			dat[k]=(b-a)-dat[k];
			return;
		}
		setchild(k,b-a);
		change(l,r,k*2,a,(a+b)/2);
		change(l,r,k*2+1,(a+b)/2,b);
		dat[k]=dat[k*2]+dat[k*2+1];
	}
	void change(int l,int r)
	{
		change(l,r,1,0,N);
	}
	int get(int l,int r,int k,int a,int b)
	{
		setchild(k,b-a);
		if(r<=a||b<=l) return 0;
		if(l<=a&&b<=r) return dat[k];
		return get(l,r,k*2,a,(a+b)/2)+get(l,r,k*2+1,(a+b)/2,b);
	}
	int get(int l,int r)
	{
		return get(l,r,1,0,N);
	}
};

segtree seg[22];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<22;i++) seg[i].init(N);
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<22;j++)
		{
			if((a>>j)%2==1) seg[j].change(i,i+1);
		}
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			l--;
			long long ans=0;
			for(int j=0;j<22;j++)
			{
				int num=seg[j].get(l,r);
				ans+=((1ll<<j)*num);
			}
			cout<<ans<<"\n";
		}
		else
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			l--;
			for(int j=0;j<22;j++)
			{
				if((x>>j)%2==1)
				{
					seg[j].change(l,r);
				}
			}
		}
	}
	return 0;
}