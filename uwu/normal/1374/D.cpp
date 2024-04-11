#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        vector<int> arr(n+1);
        map<int,int> m;
        for (int i=1;i<=n;++i) cin >> arr[i], m[k-arr[i]%k]++;
        m[k]=0;
        vector<pii> uwu;
        for (pii x:m) uwu.push_back({x.second,x.first});
        sort(uwu.begin(),uwu.end());
        if (uwu.back().second==k) cout << 0 << '\n';
        else cout << ((ll)uwu.back().first-(ll)1)*(ll)k+(ll)uwu.back().second+(ll)1 << '\n';
    }
}