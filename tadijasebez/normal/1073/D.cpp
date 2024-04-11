#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int nxt[N],pre[N],fir,f[N],tsz,a[N];
ll sum;
void Add(int id)
{
	tsz++;f[tsz]=id;
	if(!fir) nxt[tsz]=pre[tsz]=fir=tsz;
	else
	{
		nxt[pre[fir]]=tsz;
		pre[tsz]=pre[fir];
		nxt[tsz]=fir;
		pre[fir]=tsz;
	}
	sum+=a[id];
}
void Del(int x)
{
	sum-=a[f[x]];
	nxt[pre[x]]=nxt[x];
	pre[nxt[x]]=pre[x];
}
int main()
{
	int n,i;ll T;
	scanf("%i %lld",&n,&T);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Add(i);
	int sz=n;
	ll ans=0;
	int cur=fir;
	while(1)
	{
		ans+=T/sum*sz;
		T%=sum;
		while(T>=a[f[cur]])
		{
			ans++;
			T-=a[f[cur]];
			cur=nxt[cur];
		}
		Del(cur);
		cur=nxt[cur];
		sz--;
		if(sz==0) break;
	}
	printf("%lld\n",ans);
	return 0;
}