#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll arr[MAXN], n, k;
int cnt[151];
ll tot=1;

bool check(ll ans){
    ms(cnt,0), cnt[0]=1;
    ll good=1;
    for (int i=1;i<=n;++i){
        int rt;
        for (int j=0;j<=100;++j) if (cnt[j]){ rt=j, cnt[j]--; break; }
        good--;
        for (int j=0;j<arr[i]-1;++j){
            if ((rt+2+j/2)>=100) break;
            cnt[rt+2+j/2]++;
        }
        ll c1=(arr[i]-1)/2, c2=(arr[i])/2;
        rt+=2;
        good+=min(c1,ans-rt+1), good+=min(c2,ans-rt+1);
        if (good>=k) return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> arr[i], tot+=arr[i]-2;
    if (tot<k) return cout << -1 << '\n', 0;
    sort(arr+1,arr+1+n,greater<int>());
    int lo=1, hi=1e9, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    cout << lo << '\n';
}