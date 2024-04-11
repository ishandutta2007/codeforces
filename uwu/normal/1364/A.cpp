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
        int n,x; cin >> n >> x;
        vector<int> arr(n+1);
        int tot=0;
        for (int i=1;i<=n;++i) cin >> arr[i], tot+=arr[i];
        if (tot%x!=0){ cout << n << '\n'; continue;}
        int front=1,back=1;
        for (;front<=n;++front){
            if (arr[front]%x!=0) break;
        }
        for (;back<=n;++back){
            if (arr[n-back+1]%x!=0) break;
        }
        cout << n-min(front,back) << '\n';
    }
}