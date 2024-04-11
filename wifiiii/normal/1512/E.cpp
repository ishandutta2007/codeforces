#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int len=r-l+1;
        auto chk = [&](int len, int l, int s) -> int {
            if(!len) return s==0;
            ll mn=1ll*(l+l+len-1)*len/2,mx=1ll*(n-len+1+n)*len/2;
            if(s<mn || s>mx) return 0;
            return 1;
        };
        if(!chk(len,1,s)) {
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans(n+1),vis(n+2);
        int cur=1;
        for(int j=l;j<=r;++j) {
            for(int i=cur;i<=n;++i) {
                if(vis[i]) continue;
                if(chk(len-(j-l)-1,i+1,s-i)) {
                    ans[j]=i;
                    vis[i]=1;
                    ++cur;
                    s-=i;
                    break;
                }
            }
        }
        cur=1;
        for(int i=1;i<=n;++i) {
            if(ans[i]) continue;
            while(vis[cur]) ++cur;
            ans[i]=cur;
            vis[cur]=1;
        }
        for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;
    }
}