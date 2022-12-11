#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
template<typename _T> inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template<typename _T, typename... args> void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }
 
#ifdef LOCAL
#define _upgrade ios_base::sync_with_stdio(0);
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif
 
// ********************** CODE ********************** //
 
struct Matching {
    int n;
    vector<int> *G, match, vis;
    
    bool dfs(int v)
    {
        vis[v] = 1;
        for(auto u: G[v])
        {
            if(!match[u] || (!vis[match[u]] && dfs(match[u])))
            {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    
    void calc()
    {
        bool ok = 1;
        while(ok)
        {
            ok = 0;
            for(int i = 1; i <= n; i++)
                if(!match[i] && dfs(i)) 
                    ok = 1;
            for(int i = 1; i <= n; i++)
                vis[i] = 0;
        }
    }
 
    Matching(int _n, vector<int> *_G) : n(_n), G(_G)
    {
        match.resize(n + 1, 0);
        vis.resize(n + 1, 0);
    }
};
 
const int D = 11;
const int N = (1 << 10) + 7;
 
int d, n, X[N];
vector<int> G[2 * N];
vector<pair<int, int>> V[D];
 
bool vis[N];
 
int main()
{
    _upgrade
    
    cin >> d >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int x = 0;
        for(int j = d - 1; j >= 0; j--)
        {
            x *= 2;
            if(s[j] == '1')
                x++;
        }
        X[i] = x;
    }
 
    sort(X + 1, X + n + 1);
    n = unique(X + 1, X + n + 1) - X - 1;
    sort(X + 1, X + n + 1);
 
    for(int i = 1; i <= n; i++)
    {
        V[__builtin_popcount(X[i])].push_back({X[i], i});
    }
 
    Matching m(2 * n, G);
    for(int i = d - 1; i > 0; i--)
    {
        for(auto x: V[i])
        {
            for(int j = 1; j <= n; j++)
            {
                if((X[j] | x.first) == X[j] && __builtin_popcount(X[j]) > i)
                {
                    G[2 * x.second - 1].push_back(2 * j);
                    G[2 * j].push_back(2 * x.second - 1);
                }
            }
        }
        m.calc();
    }
 
    vector<int> moves;
    for(int i = n; i >= 1; i--)
    {
        if(!vis[i])
        {
            moves.push_back(0);
            int id = i;
            moves.push_back(X[id]);
            vis[id] = true;
            while(m.match[2 * id] != 0)
            {
                id = (m.match[2 * id] + 1) / 2;
                moves.push_back(X[id]);
                vis[id] = true;
            }
        }
    }
 
    reverse(all(moves));
    moves.pop_back();
 
    vector<int> ans;
 
    vector<bool> state(d, 0);
    for(auto x: moves)
    {
        if(x == 0)
        {
            ans.push_back(0);
            for(int i = 0; i < d; i++)
                state[i] = 0;
        }
        else
        {
            for(int i = 0; i < d; i++)
            {
                assert(((x >> i) & 1) || !state[i]);
                if(((x >> i) & 1) && !state[i])
                {
                    state[i] = 1;
                    ans.push_back(i + 1);
                }
            }
        }
    }
 
    cout << sz(ans) << "\n";
    for(auto x: ans)
    {
        if(x > 0)
            cout << x - 1 << " ";
        else
            cout << "R ";
    }
 
    return 0;
}