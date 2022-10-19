#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        int x[n+1],cnt[n+1],suf[n+1];
        x[n]=2*0x3f3f3f3f;
        cnt[n]=suf[n]=0;
        for (int i=0;i<n;++i) cin >> x[i];
        for (int i=0,a;i<n;++i) cin >> a;
        sort(x,x+n);
        deque<int> q;
        for (int i=0;i<n;++i){
            q.push_front(x[i]);
            while (q.size()>1&&q.back()<x[i]-k) q.pop_back();
            cnt[i]=q.size();
        }
        for (int i=n-1;i>=0;--i){
            suf[i]=max(suf[i+1],cnt[i]);
        }
        int ans=0;
        for (int i=0;i<=n-1;++i){
            ans=max(ans,cnt[i]+suf[lower_bound(x,x+1+n,x[i]+k+1)-x]);
        }
        cout << ans << '\n';
    }
}