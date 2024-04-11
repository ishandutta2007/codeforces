#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k,z; cin >> n >> k >> z;
        vector<int> arr(n+1);
        int tot=0,ans=0;
        priority_queue<pii> pq;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            if (i<=k+1) tot+=arr[i];
            if (i>=2) pq.push({arr[i]+arr[i-1],i});
        }
        int add=0;
        ans=max(ans,tot);
        for (int i=k+1,cnt=1;i>=3;i-=2,cnt++){
            if (cnt>z) break;
            ans=max(ans,tot+add-arr[i]+arr[i-2]);
            if (i==3) continue;
            while (pq.top().s>=i-1) pq.pop();
            tot-=arr[i]; tot-=arr[i-1];
            add=pq.top().f*cnt;
            ans=max(ans,tot+add);
        }
        cout << ans << '\n';
    }
}