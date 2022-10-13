#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
ll a[100001];
int n,k;
ll f(ll num, int spl) {
    if(num%spl==0) {
        ll ans = (num/spl)*1LL*(num/spl)*1LL*spl;
        return ans;
    }
    ll nl = (num+spl-1)/spl;
    ll x = nl*1LL*spl-num;
    ll ans = nl*1LL*nl*1LL*(spl-x)+(nl-1)*1LL*(nl-1)*1LL*x;
    return ans;
}
struct cmp {
    bool operator()(const pair<int,int> &x, const pair<int,int> &y) {
    ll c = f(a[x.f],x.s)-f(a[x.f],x.s+1);
    ll d = f(a[y.f],y.s)-f(a[y.f],y.s+1);
    if(c==d) return x.f<y.f;
    return c>d;

    }
};
int main() {
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    set<pair<int,int>,cmp> nums;
    for(int i=0;i<n;i++) nums.insert({i,1});
    int numSpl = n;
    ll ans = 0;
    for(int i=0;i<n;i++) ans+=a[i]*1LL*a[i];
    while(numSpl<k) {
        auto temp = nums.begin();
        int idx = (*temp).f;
        int spl = (*temp).s;
        ll sub = f(a[idx],spl)-f(a[idx],spl+1);
        ans-=sub;
        ++numSpl;
        nums.erase(temp);
        nums.insert({idx,spl+1});
    }
    cout << ans << endl;
}