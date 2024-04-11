#include<bits/stdc++.h>

using namespace std;

#define F(i, a, b) for(auto i = (a); i < (b); ++i)
#define f(i, n) F(i, 0, n)
#define re return
#define pb push_back
#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

vector<int> v[150050];
int was[150500];
int dfs(int w){
    if(was[w]) re 0;
    int ans = 0;
    was[w] = 1;
    ans = 1;
    for(auto to : v[w]) ans += dfs(to);
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    f(i, m){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll need = 0;
    F(i, 1, n+1) if(!was[i]){
        ll cnt = dfs(i);
        need += cnt*(cnt-1)/2;
    }
    cout << (need == m ? "YES" : "NO");
}