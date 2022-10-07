#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
int n,m,q,d1[100005],d2[100005];
vector<int>s[100005];
ll ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s[min(a,b)].push_back(max(a,b));
		d1[max(a,b)]++;
		d2[min(a,b)]++;
	}
	for(int i=1;i<=n;i++)ans+=1ll*d1[i]*d2[i];
	printf("%lld\n",ans);
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		for(vector<int>::iterator it=s[x].begin();it!=s[x].end();it++)
		{
			s[*it].push_back(x);
			ans-=1ll*d1[*it]*d2[*it];
			d2[*it]++;
			d1[*it]--;
			ans+=1ll*d1[*it]*d2[*it];
		}
		s[x].clear();
		ans-=1ll*d1[x]*d2[x];
		d1[x]+=d2[x];
		d2[x]=0;
		printf("%lld\n",ans);
	}
	return 0;
}