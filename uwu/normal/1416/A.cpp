#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;

int seen[MAXN], arr[MAXN], best[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) seen[i]=0, best[i]=0, ans[i]=0x3f3f3f3f;
        for (int i=1,a;i<=n;++i){
            cin >> a; arr[i]=a;
            best[a]=max(best[a],i-seen[a]);
            seen[a]=i;
        }
        for (int i=1;i<=n;++i){
            best[i]=max(best[i],n+1-seen[i]);
            ans[best[i]]=min(ans[best[i]],i);
        }
        int curr=0x3f3f3f3f;
        for (int i=1;i<=n;++i){
            curr=min(curr,ans[i]);
            cout << (curr==0x3f3f3f3f?-1:curr) << " ";
        }
        cout << '\n';
    }
}