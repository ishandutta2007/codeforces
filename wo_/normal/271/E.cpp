#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a,int b)
{
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

vector<int> divs;
vector<int> vec;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	int a;
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		in--;
		if(i==0) a=in;
		else a=gcd(a,in);
	}
	while(a%2==0) a/=2;
	for(int i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			divs.push_back(i);
			if(i*i!=a) divs.push_back(a/i);
		}
	}
	for(int i=0;i<divs.size();i++)
	{
		int tmp=divs[i];
		for(long long j=(long long)tmp*2;j<M;j*=2)
		{
			vec.push_back(j);
		}
	}
	long long ans=0;
	for(int i=0;i<divs.size();i++)
	{
		ans+=(M-divs[i]);
	}
	for(int i=0;i<vec.size();i++)
	{
		ans+=(M-vec[i]);
	}
	cout<<ans<<"\n";
	return 0;
}