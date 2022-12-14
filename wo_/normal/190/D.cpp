#include<cstdio>
#include<iostream>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

set<P> se;

vector<int> vals;

int a[400400],ca[400400];

int cnt[400400]={};

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
		vals.push_back(a[i]);
	}
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	for(int i=0;i<N;i++)
	{
		ca[i]=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),a[i]));
	}
	int s=0,t=0;
	long long ans=0;
	while(s<N)
	{
		/*
		if(t==N)
		{
			int now=ca[s];
			se.erase(P(-cnt[now],now));
			cnt[now]--;
			se.insert(P(-cnt[now],now));
			s++;
			P p=*se.begin();
			if(-p.first>=K)
			{
			//	printf("%d %d\n",s,t);
				ans++;
			}
			else break;
		}*/
		while(t<N&&(-(*se.begin()).first<K))
		{
			int now=ca[t];
		//	printf("t=%d,ca[t]=%d\n",t,ca[t]);
			se.erase(P(-cnt[now],now));
			cnt[now]++;
			se.insert(P(-cnt[now],now));
			t++;
			P p=*se.begin();
			if(-p.first>=K)
			{
		//		printf("%d %d %d\n",s,t,-p.first);
		//		ans+=(N-t+1);
				break;
			}
		}
		P p=*se.begin();
		if(-p.first<K) break;
		ans+=(N-t+1);
		int now=ca[s];
		se.erase(P(-cnt[now],now));
		cnt[now]--;
		se.insert(P(-cnt[now],now));
		s++;
		/*
		if(t!=N)
		{
			int now=ca[s];
			se.erase(P(-cnt[now],now));
			cnt[now]--;
			se.insert(P(-cnt[now],now));
			s++;
		}*/
	}
	cout<<ans<<"\n";
	return 0;
}