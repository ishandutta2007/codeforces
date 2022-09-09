#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
const int inf=1e9+7;
int a[N],b[N],mn[N],cnt[N];
ll ans[N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) mn[i]=inf;
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&a[i],&b[i]);
		cnt[a[i]]++;
		mn[a[i]]=min(mn[a[i]],a[i]>b[i]?b[i]+n:b[i]);
	}
	//int cir=0;
	//for(i=1;i<=n;i++) cir=max(cir,cnt[i]);//,printf("mn:%i\n",mn[i]);
	//int mx=0;
	//for(i=1;i<=n;i++) mx=max(mx,mn[i]-(cir-cnt[i]+1)*n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cnt[j]==0) continue;
			int dis=0;
			if(j<i) dis=n-(i-j);
			else dis=j-i;
			ans[i]=max(ans[i],(ll)(cnt[j]-1)*n+dis+mn[j]-j);
			//printf("%lld ",(ll)(cnt[j]-1)*n+dis+mn[j]-j);
		}
		//printf("\n");
		//ans[i]=mx+(ll)n*cir-i;
		//if(cir==cnt[i]-1) mx=max(mx,mn[i]+n);
		//mx=max(mx,mn[i]+n-(cir-cnt[i]+1)*n);
	}
	for(i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}