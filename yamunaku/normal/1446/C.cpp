//
// Created by yamunaku on 2020/11/15.
//

#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

template<int char_size>
struct TrieNode {
    int nxt[char_size];
    int dp;

    int exist;
    vector<int> accept;

    TrieNode() : exist(0), dp(0) {
        memset(nxt, -1, sizeof(nxt));
    }
};

template<int char_size, int margin>
struct Trie {
    using Node = TrieNode<char_size>;

    vector<Node> nodes;
    int root;

    Trie() : root(0) {
        nodes.push_back(Node());
    }

    void update_direct(int node, int id) {
        nodes[node].accept.push_back(id);
    }

    void update_child(int node, int child, int id) {
        ++nodes[node].exist;
    }

    void add(const string &str, int str_index, int node_index, int id) {
        if (str_index == str.size()) {
            nodes[node_index].dp++;
            update_direct(node_index, id);
        } else {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1) {
                nodes[node_index].nxt[c] = (int) nodes.size();
                nodes.push_back(Node());
            }
            add(str, str_index + 1, nodes[node_index].nxt[c], id);
            update_child(node_index, nodes[node_index].nxt[c], id);
        }
    }

    void add(const string &str, int id) {
        add(str, 0, 0, id);
    }

    void add(const string &str) {
        add(str, nodes[0].exist);
    }

    void query(const string &str, const function<void(int)> &f, int str_index, int node_index) {
        for (auto &idx : nodes[node_index].accept) f(idx);
        if (str_index == str.size()) {
            return;
        } else {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1) return;
            query(str, f, str_index + 1, nodes[node_index].nxt[c]);
        }
    }

    void query(const string &str, const function<void(int)> &f) {
        query(str, f, 0, 0);
    }

    int count() const {
        return (nodes[0].exist);
    }

    int size() const {
        return ((int) nodes.size());
    }

    int calc() {
        int sz = nodes.size();
        per(i, sz) {
            int &k = nodes[i].dp;
            int x = 0, y = 0;
            if (nodes[i].nxt[0] != -1) {
                x = nodes[nodes[i].nxt[0]].dp;
            }
            if (nodes[i].nxt[1] != -1) {
                y = nodes[nodes[i].nxt[1]].dp;
            }
            k = max(k, x + min(y, 1));
            k = max(k, y + min(x, 1));
        }
        return nodes[0].dp;
    }
};

int main() {
    CFS;
    int n;
    cin >> n;
    vi a(n);
    Trie<2, '0'> tr;
    rep(i, n) {
        cin >> a[i];
        int tmp = a[i];
        string s;
        rep(j, 30) {
            if (tmp & 1) s.push_back('1');
            else s.push_back('0');
            tmp >>= 1;
        }
        reverse(all(s));
        tr.add(s);
    }
    cout << n - tr.calc() << endl;
    return 0;
}