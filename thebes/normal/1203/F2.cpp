#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int MM = 3e6+6;
int n, r, i, x, y, dp[MM], ans, ans2;
vector<pii> a, b;

int main(){
    for(scanf("%d%d",&n,&r),i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        if(y>=0) a.push_back({x,y});
        else b.push_back({x,y});
    }
    sort(a.begin(),a.end(),[](pii i,pii j){return i.first<j.first;});
    sort(b.begin(),b.end(),[](pii i,pii j){return i.first+i.second>j.first+j.second;});
    for(auto v : a){
        if(v.first<=r) r += v.second, ans++;
    }
    for(auto v : b){
        for(i=max(0,v.first+v.second);i<=r+v.second;i++)
            dp[i]=max(dp[i],dp[i-v.second]+1);
    }
    for(i=0;i<=r;i++) ans2=max(ans2,dp[i]);
    printf("%d\n",ans+ans2);
    return 0;
}