#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const ll MN = 4e6+6;
ll n, i, j, f, arr[MN], hm[MN], c[MN], ii[MN], ans, lst[MN];

void go(int x){
    if(lst[x]==i) return;
    lst[x] = i;
    c[x]++;
    if(c[x]>=3) return;
    int nxt;
    for(int y=x;y;y-=y&-y){
        nxt = y&-y;
        if(lst[x^nxt]==i) continue;
        go(x^nxt);
    }
}

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    for(i=n;i>=1;i--){
        ll sna = 0;
        for(int k=21;k>=0;k--){
            if(arr[i]&(1<<k)) continue;
            sna += (1<<k);
            if(c[sna]<2) sna -= (1<<k);
        }
        if(i<=n-2) ans = max(ans, sna|arr[i]);
        go(arr[i]);
    }
    printf("%d\n",ans);
    return 0;
}