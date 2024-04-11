#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
const int max_n=1e6+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		int len;
		scanf("%d",&len);
		for(int i=2;i<=m;++i)
		{
			int b;
			scanf("%d",&b);
			len=gcd(len,b);
		}
		vector<vector<int> > S(len);
		for(int i=1;i<=n;++i)
			S[i%len].push_back(a[i]);
		long long sum=0;
		for(int i=0;i<len;++i)
		{
			sort(S[i].begin(),S[i].end());
		 	for(int j=0;j+1<int(S[i].size());j+=2)
		 	{
		 		if(S[i][j+1]<=0)
		 			S[i][j]=-S[i][j],S[i][j+1]=-S[i][j+1];
			}
			sort(S[i].begin(),S[i].end());
			if(S[i][0]+S[i][1]<0)
				S[i][0]=-S[i][0],S[i][1]=-S[i][1];
			sort(S[i].begin(),S[i].end());
			sum+=*S[i].begin();
		}
		if(sum<0)
		{
			for(int i=0;i<len;++i)
				S[i][0]=-S[i][0];
		}
		long long ans=0;
		for(int i=0;i<len;++i)
		{
			for(int j=0;j<int(S[i].size());++j)
				ans+=S[i][j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}