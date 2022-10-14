#include <bits/stdc++.h>
using namespace std;


#pragma GCC optimize("Ofast") // optimizes doubles + vectors
//using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e6, M = 1e9+7;
const ull INF = 1e18;
#define runcase LOL
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<array<int, 2>> var2;
typedef vector<array<int, 3>> var3;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define DOR(tt, X) for(int tt = X; tt >= 0; --tt)
#define pb push_back
#define ar array
#define all(X) X.begin(),X.end()
#define vt vector
#define sz(X) int(X.size())
#define ub upper_bound
#define lb lower_bound


vector<int> dfs(int c, vvi &adj, int p = -1) {
    vector<int> ans={c};
    for (int e : adj[c])
    {
        if(e != p)
        {
            vector<int> v = dfs(e, adj, c);
            for(int i : v)
            {
                ans.pb(i);
            }
        }
    }

    return ans;

}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    while(t--) {
        string s;
        cin >> s;
        vector<bool> vis(26);
        if(sz(s) > 26) {
            cout << "NO\n";
            continue;
        }
        bool works = 1;
        
        vi pos(26, -1);
        for(char ch : s) {
            if(vis[ch - 'a']) {
                works = 0;
                break;
            }
            vis[ch -'a'] = 1;
        }
        works &= vis[0];
        if(!works) {
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < 26; ++i) {
            if(i > 0 && vis[i] && !vis[i - 1]) {
                works = false;
                cout << "NO\n";
                break;
            }
        }
        if(!works)
        {
            continue;
        }
        int n = sz(s);
        fill(all(vis), 0);
        for(int i =0; i < sz(s); ++i)
        {
            pos[s[i] - 'a'] = i; 
        }
        
        int l = pos[0], r = pos[0];
        vis[l] = 1;
        int nxt = 0;
        while(nxt < 26 && l >= 0 && r < sz(s)) {
            ++nxt; 
            if(nxt == 26)
                break;
            int nextPos = pos[nxt];
            if(nextPos < 0 || nextPos >= n)
            {
                break;
            }
            if(nextPos == l - 1){
                assert(nextPos != -1);
                vis[nextPos] = 1;
                --l;
            } else if(nextPos == r + 1) {
                assert(nextPos != -1);
                vis[nextPos] = 1;
                ++r;
            } else {
                break;
            }
        }
        for(int i = 0; i < sz(s); ++i) {
            works &= vis[i] == 1;
        }

        cout << (works ? "YES\n" : "NO\n");

    }
}