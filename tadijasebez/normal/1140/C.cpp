#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,k,i;
    scanf("%i %i",&n,&k);
    multiset<int> st;
    ll sum=0,ans=0;
    vector<pair<int,int>> v(n);
    for(auto &p:v) scanf("%i %i",&p.second,&p.first);
    sort(v.begin(),v.end());
    for(i=n-1;~i;i--)
	{
		st.insert(v[i].second);
		sum+=v[i].second;
		if(st.size()>k)
		{
			sum-=*st.begin();
			st.erase(st.begin());
		}
		ans=max(ans,sum*v[i].first);
	}
	printf("%lld\n",ans);
	return 0;
}