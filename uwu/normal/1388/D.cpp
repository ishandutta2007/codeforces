#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

ll a[MAXN],b[MAXN];
vector<int> in[MAXN];
vector<int> ans;

void push(int curr){
    for (int x:in[curr]){
        if (a[x]>0) push(x);
    }
    ans.push_back(curr);
    for (int x:in[curr]){
        if (a[x]<=0) push(x);
    }
}

ll solve(int curr){
    for (int x:in[curr]){
        ll tmp=solve(x);
        if (tmp>0) a[curr]+=tmp;
    }
    return a[curr];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i){
        cin >> b[i];
        in[b[i]].push_back(i);
    }
    for (int i=1;i<=n;++i){
        if (b[i]==-1) solve(i), push(i);
    }
    ll tot=0;
    for (int i=1;i<=n;++i) tot+=a[i];
    cout << tot << '\n';
    for (int x:ans) cout << x << " ";
    cout << '\n';
}