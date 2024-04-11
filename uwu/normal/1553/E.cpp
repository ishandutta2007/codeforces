#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

int n, k, a[MAXN], cand[MAXN], vis[MAXN];

int swaps(int shift){
    for (int i=1;i<=n;++i) vis[i]=0;
    int ret=n;
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        ret--;
        for (int j=i;;j=(a[j]+shift-1)%n+1){
            if (vis[j]) break;
            vis[j]=1;
        }
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        for (int i=0;i<n;++i) cand[i]=0;
        for (int i=1;i<=n;++i){
            cin >> a[i];
            cand[(i-a[i]+n)%n]++;
        }
        vector<int> ans;
        for (int i=0;i<n;++i){
            if (cand[i]>=n/3){
                // cout << i << " " << swaps(i) << '\n';
                if (swaps(i)<=k) ans.push_back(i);
            }
        }
        cout << ans.size() << " ";
        for (int x:ans) cout << x << " ";
        cout << '\n';
    }
}