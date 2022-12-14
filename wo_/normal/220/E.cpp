#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int a[100100];
vector<int> vals;
vector<int> ids[100100];
int ca[100100];

struct BIT{
	int N;
	int bit[100100];
	void init(int N_)
	{
		N=N_;
		for(int i=1;i<=N;i++) bit[i]=0;
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
		while(i>0)
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

BIT pre,suf;

int main()
{
	int N;
	long long K;
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
		vals.push_back(a[i]);
	}
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	for(int i=0;i<N;i++)
	{
		int aa=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),a[i]));
		ids[aa].push_back(i);
	}
	int cnt=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<ids[i].size();j++)
		{
			ca[ids[i][j]]=cnt;
			cnt++;
		}
	}
	pre.init(cnt);suf.init(cnt);
	long long all=0;
	for(int i=0;i<N;i++)
	{
		all+=(i-suf.sum(ca[i]));
		suf.add(ca[i],1);
	}
	if(all<=K)
	{
		long long ans=((long long)N*(N-1))/2;
		cout<<ans<<"\n";
		return 0;
	}
	int s=0,t=0;
	long long num=0;
	long long ans=0;
	long long req=all-K;
	while(s<N-1)
	{
		while(t<N&&num<req)
		{
			int x=ca[t];
			int plus=(pre.sum()-pre.sum(x)+suf.sum(x-1));
			num+=plus;
			suf.add(x,-1);
			t++;
		}
		//printf("%d %d %d\n",s,t,num);
		if(s!=0) ans+=(N-t);
		int x=ca[s];
		int minus=(pre.sum()-pre.sum(x)+suf.sum(x));
		num-=minus;
		pre.add(x,1);
		s++;
	}
	cout<<ans<<"\n";
	return 0;
}