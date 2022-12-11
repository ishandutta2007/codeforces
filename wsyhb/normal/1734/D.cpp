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
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		typedef pair<long long,long long> P;
		vector<P> L,R;
		long long now=0,mn=0;
		for(int i=k-1;i>=1;--i)
		{
			now+=a[i];
			mn=min(mn,now);
			if(now>0)
			{
				L.push_back(P(now,mn));
				now=mn=0;
			}
		}
		long long lst_L=mn;
		now=mn=0;
		for(int i=k+1;i<=n;++i)
		{
			now+=a[i];
			mn=min(mn,now);
			if(now>0)
			{
				R.push_back(P(now,mn));
				now=mn=0;
			}
		}
		long long lst_R=mn;
		reverse(L.begin(),L.end());
		reverse(R.begin(),R.end());
		long long cur=a[k];
		while(!L.empty()||!R.empty())
		{
			if(!L.empty()&&cur+L.back().second>=0)
			{
				cur+=L.back().first;
				L.pop_back();
			}
			else if(!R.empty()&&cur+R.back().second>=0)
			{
				cur+=R.back().first;
				R.pop_back();
			}
			else
				break;
		}
		if(L.empty()&&cur+lst_L>=0)
			puts("YES");
		else if(R.empty()&&cur+lst_R>=0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}