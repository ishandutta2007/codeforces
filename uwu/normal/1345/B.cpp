#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=25822;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    vector<ll> arr;
    ll tot=0;
    for (int i=1;i<=MAXN;++i){
        tot+=i;
        arr.push_back(tot*3-i);
    }
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        int ans=0;
        while (!(n<2)){
            n-=arr[(upper_bound(arr.begin(),arr.end(),n)-(arr.begin()))-1];
            ans++;
        }
        cout << ans << '\n';
    }
}