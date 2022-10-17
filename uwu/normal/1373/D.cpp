#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

vector<int> arr; int n;

ll solve1(){
    ll curr=0,prev=0,ans=0;
    for (int i=2;i<=n;i+=2){
        curr+=arr[i]-arr[i-1];
        prev=min(prev,curr);
        ans=max(ans,curr-prev);
    }
    return ans;
}

ll solve2(){
    ll curr=0,prev=0,ans=0;
    for (int i=3;i<=n;i+=2){
        curr+=arr[i-1]-arr[i];
        prev=min(prev,curr);
        ans=max(ans,curr-prev);
    }
    return ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        arr.clear(); arr.resize(n+1);
        for (int i=1;i<=n;++i) cin >> arr[i];
        ll tot=0;
        for (int i=1;i<=n;i+=2) tot+=arr[i];
        cout << tot+max(solve1(),solve2()) << '\n';
    }
}