#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        vector<int> arr(n+1);
        bool peak[n+1]={0};
        for (int i=1;i<=n;++i){ cin >> arr[i]; }
        for (int i=2;i<=n-1;++i){
            if (arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                peak[i]=1;
            }
        }
        k-=2;
        int cnt=0;
        for (int i=2;i<2+k;++i){
            cnt+=peak[i];
        }
        int ans=cnt,ansl=2;
        for (int i=2;i+k<n;++i){
            cnt-=peak[i];
            cnt+=peak[i+k];
            if (cnt>ans){
                ans=cnt;
                ansl=i+1;
            }
        }
        cout << ans+1 << " " << ansl-1 << '\n';

        
    }
}