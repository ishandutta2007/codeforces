#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 1e3+5;
int n, i, fl, cnt[MN], last;
pair<int,int> arr[MN];
queue<int> w;
vector<pair<int,int>> sol;

int main(){
    for(scanf("%d",&n),i=1;i<n;i++){
        scanf("%d%d",&arr[i].first,&arr[i].second);
        if(arr[i].first!=n&&arr[i].second!=n){
            printf("NO\n");
            return 0;
        }
        cnt[arr[i].first]++;
        cnt[arr[i].second]++;
    }
    for(i=1;i<=n;i++){
        if(cnt[i]>i){
            printf("NO\n");
            return 0;
        }
    }
    for(i=n-1;i>=1;i--){
        if(!cnt[i]) w.push(i);
    }
    last = n;
    for(i=n-1;i>=1;i--){
        if(!cnt[i]) continue;
        cnt[i]--;
        while(cnt[i]--){
            int t = w.front(); w.pop();
            if(t > i){
                printf("NO\n");
                return 0;
            }
            sol.push_back({last,t});
            last = t;
        }
        sol.push_back({i,last});
        last = i;
    }
    printf("YES\n");
    for(auto v : sol)
        printf("%d %d\n",v.first,v.second);
    return 0;
}