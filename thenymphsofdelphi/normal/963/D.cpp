#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

#define trie __trie__

const int N = 1e5 + 5, M = 26;

struct Node{
    int p, pch;
    int nxt[26], go[26], link, exlink;
    int leaf;
    
    Node(){
        memset(nxt, -1, sizeof(nxt)); memset(go, -1, sizeof(go));
        link = exlink = -1;
        leaf = -1;
    }
};

vector <Node> trie(1);

void add(string s, int idx){
    int u = 0;
    For(i, 0, isz(s)){
        if (trie[u].nxt[s[i] - 'a'] < 0){
            trie[u].nxt[s[i] - 'a'] = isz(trie);
            trie.emplace_back();
            trie.back().p = u; trie.back().pch = s[i] - 'a';
        }
        u = trie[u].nxt[s[i] - 'a'];
    }
    trie[u].leaf = idx;
}

int get_link(int u);

int get_go(int u, int c){
    if (trie[u].go[c] < 0){
        if (trie[u].nxt[c] >= 0){
            trie[u].go[c] = trie[u].nxt[c];
        }
        else{
            trie[u].go[c] = (u ? get_go(get_link(u), c) : 0);
        }
    }
    return trie[u].go[c];
}

int get_link(int u){
    if (trie[u].link < 0){
        if (!u || !trie[u].p){
            trie[u].link = 0;
        }
        else{
            trie[u].link = get_go(get_link(trie[u].p), trie[u].pch);
        }
    }
    return trie[u].link;
}

int get_exlink(int u){
    if (trie[u].exlink < 0){
        if (!u){
            trie[u].exlink = 0;
        }
        else if (trie[get_link(u)].leaf >= 0){
            trie[u].exlink = get_link(u);
        }
        else{
            trie[u].exlink = get_exlink(get_link(u));
        }
    }
    return trie[u].exlink;
}

string s;
int n;
int k[N]; string m[N];

vi pos[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> s;
    cin >> n;
    ForE(i, 1, n){
        cin >> k[i] >> m[i];
    }
    ForE(i, 1, n){
        add(m[i], i);
    }
    int u = 0;
    For(i, 0, isz(s)){
        u = get_go(u, s[i] - 'a');
        int t = u;
        while (t){
            if (trie[t].leaf >= 0){
                pos[trie[t].leaf].push_back(i);
            }
            t = get_exlink(t);
        }
    }
    ForE(i, 1, n){
        if (isz(pos[i]) < k[i]){
            cout << -1 << endl;
            continue;
        }
        int ans = isz(s) + 1;
        For(j, k[i] - 1, isz(pos[i])){
            ans = min(ans, pos[i][j] - (pos[i][j - k[i] + 1] - isz(m[i]) + 1) + 1);
        }
        cout << ans << endl;
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/