#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct Item{
    int id, h;
    bool operator<(const Item &x) const{
        return h>x.h;
    }
} arr[MAXN];
priority_queue<Item> pq;
int ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        while (!pq.empty()) pq.pop();
        int n, m, x; cin >> n >> m >> x;
        for (int i=1;i<=n;++i) cin >> arr[i].h, arr[i].id=i;
        for (int i=1;i<=m;++i) pq.push({i,0});
        sort(arr+1,arr+1+n);
        int mx=0;
        for (int i=1;i<=n;++i){
            auto [id,h]=pq.top(); pq.pop();
            h+=arr[i].h;
            mx=max(mx,h);
            ans[arr[i].id]=id;
            pq.push({id,h});
        }
        int mn=pq.top().h;
        if (mx-mn>x) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            for (int i=1;i<=n;++i) cout << ans[i] << " ";
            cout << '\n';
        }
    }
}