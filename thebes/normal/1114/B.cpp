#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5+5;
ll n, k, m, arr[MN], i, j, ans, cnt;
pair<ll,ll> vec[MN];

int main(){
    for(scanf("%lld%lld%lld",&n,&m,&k),i=1;i<=n;i++)
        scanf("%lld",&arr[i]), vec[i]={arr[i],i};
    sort(vec+1,vec+n+1,[](pair<ll,ll> i,pair<ll,ll> j){return i.first>j.first;});
    memset(arr, 0, sizeof(arr));
    for(i=1;i<=m*k;i++){
        ans += vec[i].first;
        arr[vec[i].second] = 1;
    }
    printf("%lld\n",ans);
    cnt = 0;
    for(i=1;i<=n;i++){
        cnt += arr[i];
        if(cnt == m){
            cnt = 0;
            if(k!=1) printf("%lld ",i), k--;
        }
    }
    printf("\n");
    return 0;
}