#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=0;i<=n-1;++i)
			scanf("%d",a+i);
		vector<int> pf;
		int t=n;
		for(int i=2;i*i<=t;++i)
		{
			if(t%i==0)
			{
				pf.push_back(i);
				while(t%i==0)
					t/=i; 
			}
		}
		if(t>1)
			pf.push_back(t);
		int cnt=pf.size();
		assert(cnt<=6);
		vector<vector<long long> > sum(cnt);
		multiset<long long> S;
		for(int i=0;i<cnt;++i)
		{
			int d=pf[i],len=n/d;
			sum[i].resize(len);
			for(int j=0;j<n;++j)
				sum[i][j%len]+=a[j];
			for(int j=0;j<len;++j)
				S.insert(sum[i][j]*len);
		}
		printf("%lld\n",*S.rbegin()); 
		while(q--)
		{
			int p,x;
			scanf("%d%d",&p,&x);
			--p;
			for(int i=0;i<cnt;++i)
			{
				int len=sum[i].size();
				int pos=p%len;
				S.erase(S.find(sum[i][pos]*len));
				sum[i][pos]+=x-a[p];
				S.insert(sum[i][pos]*len);
			}
			a[p]=x;
			printf("%lld\n",*S.rbegin());
		}
	}
	return 0;
}