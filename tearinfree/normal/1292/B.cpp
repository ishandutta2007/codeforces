#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli INF = 1000000000000000000ll;
lli mul(lli a,lli b) {
    if(a==0 || b==0) return 0;
    else if(INF/a<=b || a*b>=INF) return INF;
    else return a*b;
}

vector<pair<lli,lli>> arr;

lli get_dist(pair<lli,lli> a, pair<lli,lli> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int main() {
    lli pos[2], a[2], b[2], cur[2], t;
    scanf("%lld%lld%lld%lld%lld%lld",pos,pos+1,a,a+1,b,b+1);
    scanf("%lld%lld%lld",cur,cur+1,&t);

    while(true) {
        arr.push_back({pos[0], pos[1]});
        
        for(int i=0;i<2;i++) pos[i] = mul(pos[i], a[i]) + b[i];
        if(pos[0] >= INF || pos[1] >= INF) break;
    }

    int ans=0;
    for(int i=0;i<arr.size();i++) for(int j=i;j<arr.size();j++) {
        lli ds = 0;
        for(int k=i;k<j;k++) {
            ds = min(INF, ds + get_dist(arr[k], arr[k+1]));
        }
        if(ds + min(get_dist(arr[i], {cur[0],cur[1]}), get_dist(arr[j], {cur[0], cur[1]})) <= t) {
            ans = max(ans, j-i+1);
        }
    }
    printf("%d\n",ans);

    return 0;
}