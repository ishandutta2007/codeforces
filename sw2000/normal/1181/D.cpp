#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

ll arr[maxn],cnt[maxn],lst[maxn];

int main()
{
	ll n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
	for(int i=1;i<=n;i++)
    {
        lst[i]=cnt[arr[i]]*m+arr[i];
        cnt[arr[i]]++;
    }
    sort(lst+1,lst+n+1);
    for(int i=1;i<=n;i++)lst[i]+=n-i;

    for(int i=0;i<q;i++)
    {
        ll tmp,ans;
        scanf("%lld",&tmp);
        if(tmp>lst[n])ans=tmp;
        else
        {
            int st=lower_bound(lst+1,lst+n+1,tmp)-lst;
            ans=tmp-(n-st+1);
        }
        if(ans%m==0)ans=m;
        else ans%=m;
        printf("%lld\n",ans);
    }
	return 0;
}