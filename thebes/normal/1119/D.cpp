#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 1e5+5;
ll arr[MN], nxt, n, q, i, ans[MN], l, r, lst, sub;
pair<ll,ll> qur[MN];
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    sort(arr+1,arr+n+1,[](ll i,ll j){return i<j;});
    for(scanf("%lld",&q),i=1;i<=q;i++){
        scanf("%lld%lld",&l,&r);
        qur[i]={r-l, i};
    }
    sort(qur+1,qur+q+1,[](pll i,pll j){return i.first<j.first;});
    for(i=1;i<=n;i++){
        if(arr[i]+1<arr[i+1]) pq.push(arr[i+1]-arr[i]-1),sub+=arr[i+1]-arr[i]-1;
    }
    for(i=1;i<=q;i++){
        while(pq.size()&&pq.top()<=qur[i].first){
            sub -= pq.size()*(pq.top()-lst);
            lst = pq.top();
            pq.pop();
        }
        ans[qur[i].second]=(arr[n]+qur[i].first-arr[1]+1)-sub+pq.size()*(qur[i].first-lst);
    }
    for(i=1;i<=q;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}