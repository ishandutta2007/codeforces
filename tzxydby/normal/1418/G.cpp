#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,a[N],v[N],c[N],h[N],l,ans;
map<int,int>mp;
vector<int>x[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!v[a[i]])
			v[a[i]]=((long long)rand())|((long long)rand()<<15)|((long long)rand()<<30)|((long long)rand()<<45);
		c[i]=x[a[i]].size();
		x[a[i]].push_back(i);
		if(c[i]%3)
			h[i]=h[i-1]+v[a[i]];
		else
			h[i]=h[i-1]-v[a[i]]*2;
	}
	mp[0]++;
	for(int i=1;i<=n;i++)
	{
		if(c[i]>=3)
		{
			int p=x[a[i]][c[i]-3];
			while(l<=p)
			{
				if(l)
					mp[h[l-1]]--;
				l++;
			}
		}
		ans+=mp[h[i]];
		mp[h[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}