#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e6;

map<char, int> nxt[N];
vector<pii> items[N];
int who[N];
int tot, n = 1;
ll ans = 0;

void add(string & s, int c, int idx){
    int v = 0;
    I(c, s){
        if(!nxt[v].count(c)){
            nxt[v][c] = n++;
        }
        v = nxt[v][c];
    }
    items[v].pb({c, idx});
}

void solve(int v, int depth = 0){
    int big = -1;
    vector<int> ch;
    I(e, nxt[v]){
        ch.pb(e.Y);
        solve(e.Y, depth + 1);
        if(big == -1 || items[e.Y].size() > items[big].size())
            big = e.Y;
    }
    if(big != -1 && items[big].size() > items[v].size())
        items[v].swap(items[big]);
    I(u, ch){
        I(it, items[u])
            items[v].pb(it);
    }
    sort(all(items[v]));
    int ptr = 0;
    while(ptr < (int)items[v].size() && items[v][ptr].X == 0)
        ++ptr;
    int l = 0;
    int old = ptr;
    while(l < old && ptr < (int)items[v].size()){
        who[items[v][l].Y] = items[v][ptr].Y;
        ++l; ++ptr;
        ans += depth;
    }
    if(l < old){
        vector<pii> kek;
        F(i, l, old)kek.pb(items[v][i]);
        items[v] = kek;
    }
    else{
        vector<pii> kek;
        F(i, ptr, (int)items[v].size())kek.pb(items[v][i]);
        items[v] = kek;
    }
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tot;
    F(i, 0, tot){
        string s;
        cin >> s;
        add(s, 0, i);
    }
    F(i, 0, tot){
        string s;
        cin >> s;
        add(s, 1, i);
    }
    solve(0);
    cout << ans << endl;
    F(i, 0, tot){
        cout << i + 1 << ' ' << who[i] + 1 << '\n';
    }
    return 0;
}