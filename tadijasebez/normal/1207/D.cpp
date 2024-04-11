#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
int a[N],b[N],id[N];
map<int,int> A,B;
map<pair<int,int>,int> C;
int F[N];
const int mod=998244353;
int main()
{
	int n;
	scanf("%i",&n);
	F[0]=1;
	for(int i=1;i<=n;i++) F[i]=(ll)F[i-1]*i%mod;
	for(int i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]),A[a[i]]++,B[b[i]]++,C[{a[i],b[i]}]++,id[i]=i;
	sort(id+1,id+1+n,[&](int i, int j){ return mp(a[i],b[i])<mp(a[j],b[j]);});
	bool ok=1;
	for(int i=2;i<=n;i++) if(b[id[i-1]]>b[id[i]]) ok=0;
	ll ans=F[n];
	ll tmp=1;
	for(auto it:A) tmp=(ll)tmp*F[it.second]%mod;
	ans=(ans-tmp+mod)%mod;
	tmp=1;
	for(auto it:B) tmp=(ll)tmp*F[it.second]%mod;
	ans=(ans-tmp+mod)%mod;
	if(ok)
	{
		tmp=1;
		for(auto it:C) tmp=(ll)tmp*F[it.second]%mod;
		ans=(ans+tmp)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}