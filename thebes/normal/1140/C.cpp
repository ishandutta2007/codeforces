#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
priority_queue<int,vector<int>,greater<int>> q;
int n, k, i, x, y; long long ans, len;
pair<int,int> a[MN];

int main(){
    for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1,[](pair<int,int>i,pair<int,int>j){return i.second>j.second;});
    for(i=1;i<=n;i++){
        q.push(a[i].first);
        len += a[i].first;
        if(q.size()>k) len-=q.top(), q.pop();
        ans = max(ans, 1LL*a[i].second*len);
    }
    printf("%lld\n",ans);
    return 0;
}