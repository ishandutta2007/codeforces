#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3001;

ll arr[MAXN],cnt[MAXN],seen[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cnt[i]=0;
        ll ans=0,curr;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            curr=0;
            cnt[arr[i]]-=1;
            for (int j=i-1;j>=1;--j){
                if (arr[j]==arr[i]){
                    ans+=curr;
                }
                curr-=seen[arr[j]]*(cnt[arr[j]]-seen[arr[j]]);
                seen[arr[j]]++;
                curr+=seen[arr[j]]*(cnt[arr[j]]-seen[arr[j]]);
            }
            for (int i=1;i<=n;++i) seen[i]=0;
            cnt[arr[i]]+=2;
        }
        cout << ans << '\n';
    }
}