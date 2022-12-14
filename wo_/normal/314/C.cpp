#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

struct BIT{
	int N;
	long long dat[100100];
	void init(int N_)
	{
		N=N_;
		for(int i=0;i<=N;i++) dat[i]=0;
	}
	void add(int i,long long x)
	{
		while(i<=N)
		{
			dat[i]+=x;
			dat[i]%=mod;
			i+=(i&(-i));
		}
	}
	long long sum(int i)
	{
		long long res=0;
		while(i>0)
		{
			res+=dat[i];
			res%=mod;
			i-=(i&(-i));
		}
		return res;
	}
};

BIT bit;

int a[100100];
int ca[100100];

int vals[100100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++) vals[i]=a[i];
	sort(vals,vals+N);
	int ln=unique(vals,vals+N)-vals;
	for(int i=0;i<N;i++) ca[i]=lower_bound(vals,vals+ln,a[i])-vals+1;
	bit.init(ln);
	for(int i=0;i<N;i++)
	{
		long long tmp=bit.sum(ca[i])+1;
		long long prv=bit.sum(ca[i])-bit.sum(ca[i]-1);
		tmp*=a[i];
		tmp-=prv;
		tmp%=mod;
		bit.add(ca[i],tmp);
	}
	cout<<bit.sum(ln)<<"\n";
	return 0;
}