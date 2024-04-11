#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=8001;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr;
        bool can[n+1]={0};
        int pre[n+1]={0};
        for (int i=1,a;i<=n;++i){
            cin >> a;
            arr.push_back(a);
            pre[i]=pre[i-1]+a;
        }
        for (int i=1;i<=n;++i){
            for (int k=0;k<=i-2;++k){
                if (pre[i]-pre[k]<=n) can[pre[i]-pre[k]]=1;
            }
        }
        int cnt=0;
        for (int i=0;i<n;++i){
            if (can[arr[i]]){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}