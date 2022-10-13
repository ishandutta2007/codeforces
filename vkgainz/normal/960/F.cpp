#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<int,int> dp[100000];
void ins(int x,int w, int v) {
    auto it = prev(dp[x].upper_bound(w));
    if(it->second>=v) return;
    ++it;
    while(it!=dp[x].end() && it->second<=v) dp[x].erase(it++);
    dp[x][w] = v;
}
int main() {
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for(int i=0;i<n;i++) dp[i][0] = 0;
    for(int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        --a, --b;
        //x -> a -> b
        auto it = prev(dp[a].lower_bound(w));
        int v = it->second+1;
        ans = max(ans,v);
        ins(b,w,v);
    }
    cout << ans << endl;
}