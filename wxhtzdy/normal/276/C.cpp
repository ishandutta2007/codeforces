#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
ll a[N],d[N],cnt[N];
int main(){
    int n,q;
    scanf("%i %i",&n,&q);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%i %i",&l,&r);
        d[l-1]++,d[r]--;
    }
    int sz=0;
    for(int i=0;i<n;i++){
        sz+=d[i],cnt[i]=sz;
    }
    sort(cnt,cnt+n);
    ll ans=0;
    for(int i=0;i<n;i++)ans+=(long long)(cnt[i]*a[i]);
    printf("%lld",ans);
    return 0;
}