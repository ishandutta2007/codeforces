#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[505], pre[505];
int main() {
    int n, k;
    cin >> n >> k;
    if(k % 2 == 0 && n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    memset(dp, 0x3f, sizeof(dp));
    // 1. cost 2, get 2k/2k-2/2k-4/.../2
    // 2. cost 1, get k
    dp[0] = 0;
    // (2, 2i)
    for(int i=2;i<=2*k;i+=2) {
        if(n<k+i/2) break;
        for(int j=i;j<=n;++j) {
            if(dp[j-i]+2<dp[j]) {
                dp[j]=dp[j-i]+2;
                pre[j]=j-i;
            }
        }
    }
    // (1, k)
    for(int j=k;j<=n;++j) {
        if(dp[j-k]+1<dp[j]) {
            dp[j]=dp[j-k]+1;
            pre[j]=j-k;
        }
    }
    if(dp[n]>=1e9) {
        cout << -1 << endl;
        return 0;
    }
    int cur=n,ans=0;
    while(cur) {
        int lst=pre[cur];
        if(dp[cur]-dp[lst]==2) {
            int d=cur-lst;
            assert(d%2==0 && 2<=d && d<=2*k);
            // get [lst+1,cur]
            cout<<"?";
            int res=k,mid=(cur+lst)/2;
            for(int i=lst+1;i<=mid;++i) cout<<" "<<i,--res;
            for(int i=1;i<=n;++i) {
                if(!res) break;
                if(i>=lst+1 && i<=cur) continue;
                --res;
                cout<<" "<<i;
            }
            cout<<endl;
            int r;
            cin>>r;
            ans^=r;
            cout<<"?";
            res=k;
            for(int i=mid+1;i<=cur;++i) cout<<" "<<i,--res;
            for(int i=1;i<=n;++i) {
                if(!res) break;
                if(i>=lst+1 && i<=cur) continue;
                --res;
                cout<<" "<<i;
            }
            cout<<endl;
            cin>>r;
            ans^=r;
        } else {
            assert(dp[cur]-dp[lst]==1);
            // get [lst+1,cur]
            assert(cur-lst==k);
            cout<<"?";
            for(int i=lst+1;i<=cur;++i) cout<<" "<<i;
            cout<<endl;
            int r;
            cin>>r;
            ans^=r;
        }
        cur=lst;
    }
    cout<<"! "<<ans<<endl;
}