#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
int c[N],l[N],f[N];
ll fuel[N];
bool go[N];
vector<int> work,leaf,wl,wd;
bool comp(int i, int j){ return fuel[i]<fuel[j];}
int main()
{
	int n,d,S,i;
	scanf("%i %i %i",&n,&d,&S);
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&c[i],&f[i],&l[i]);
		if(l[i]>=d)
		{
			fuel[i]=f[i];
			go[i]=1;
			if(c[i]==0) wl.pb(i);
			else wd.pb(i);
			work.pb(i);
		}
		if(c[i]==0) leaf.pb(i);
		sum+=c[i];
	}
	sort(wl.begin(),wl.end(),comp);
	if(leaf.size()==n)
	{
		int cnt=0;
		ll ans=0;
		for(i:wl) if(fuel[i]<=S) S-=fuel[i],cnt++,ans+=fuel[i];
		printf("%i %lld\n",cnt,ans);
		return 0;
	}
	sort(work.begin(),work.end(),comp);
	sort(wd.begin(),wd.end(),comp);
	int cnt=0,sol=0;ll ans=0,out=0;
	bool can=0;
	for(i:work)
	{
		if(fuel[i]<=S)
		{
			S-=fuel[i];
			cnt++;
			ans+=fuel[i];
			if(c[i]!=0) can=1;
		}
		else break;
		if(!can)
		{
			if(cnt>sol) sol=cnt,out=ans;
		}
		else
		{
			if(min(sum+cnt,(ll)n)>sol) sol=min(sum+cnt,(ll)n),out=ans;
		}
	}
	S+=ans;
	cnt=0;ans=0;
	if(wd.size())
	{
		i=wd.front();
		if(fuel[i]<=S)
		{
			S-=fuel[i];
			ans+=fuel[i];
			cnt++;
			if(min(sum+cnt,(ll)n)>sol) sol=min(sum+cnt,(ll)n),out=ans;
			if(min(sum+cnt,(ll)n)==sol) out=min(out,ans);
			int id=i;
			for(i:work)
			{
				if(i==id) continue;
				if(fuel[i]<=S)
				{
					S-=fuel[i];
					ans+=fuel[i];
					cnt++;
				}
				else break;
				if(min(sum+cnt,(ll)n)>sol) sol=min(sum+cnt,(ll)n),out=ans;
				if(min(sum+cnt,(ll)n)==sol) out=min(out,ans);
			}
		}
	}
	printf("%i %lld\n",sol,out);
	return 0;
}