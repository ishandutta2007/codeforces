#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y){
    if(x < y) {x = y; return true;}
    return false;
}
template<typename T> bool chmin(T &x, const T &y){
    if(x > y) {x = y; return true;}
    return false;
}
void in() {}
template<typename Head, typename ...Tail> void in(Head &&head, Tail &&...tail){
    cin >> head;
    in(forward<Tail>(tail)...);
}
void out() {cout << '\n';}
template<typename Head, typename ...Tail> void out(Head &&head, Tail &&...tail){
    cout << head << ' ';
    out(forward<Tail>(tail)...);
}
void outn() {}
template<typename Head, typename ...Tail> void outn(Head &&head, Tail &&...tail){
    cout << head << '\n';
    outn(forward<Tail>(tail)...);
}
template<typename T, typename U> void in(pair<T, U> &p){
    cin >> p.first >> p.second;
}
template<typename T, typename U> void out(pair<T, U> p){
    cout << p.first << ' ' << p.second << '\n';
}
using vi = vector<int>;
using vll = vector<ll>;
#define vec1(type, name, a, x) vector<type> name(a, x)
#define VEC1(type, a, x) vector<type>(a, x)
#define vec2(type, name, a, b, x) vector<vector<type>> name(a, VEC(type, b, x))
#define VEC2(type, a, b, x) vector<vector<type>>(a, VEC(type, b, x))
#define vec3(type, name, a, b, c, x) vector<vector<vector<type>>> name(a, VEC2(type, b, c, x))
#define VEC3(type, a, b, c, x) vector<vector<vector<type>>>(a, VEC2(type, b, c, x))
#define vec4(type, name, a, b, c, d, x) vector<vector<vector<vector<type>>>> name(a, VEC3(type, b, c, d, x))
#define VEC4(type, a, b, c, d, x) vector<vector<vector<vector<type>>>>(a, VEC3(type, b, c, d, x))
#define vec5(type, name, a, b, c, d, e, x) vector<vector<vector<vector<vector<type>>>>> name(a, VEC4(type, b, c, d, e, x))
#define VEC5(type, a, b, c, d, e, x) vector<vector<vector<vector<vector<type>>>>>(a, VEC4(type, b, c, d, e, x))
template<typename T> void vin(vector<T> &a){
    rep(i, sz(a)) cin >> a[i];
}
template<typename T> void vout(const vector<T> &a){
    for(auto &e: a) cout << e << ' ';
    cout << '\n';
}
template<typename T> void voutn(const vector<T> &a){
    for(auto &e: a) cout << e << '\n';
}
template<typename T> void unique(vector<T> &a){
    sort(all(a)), a.erase(unique(all(a)), a.end());
}
vector<int> iota(int n){
    vector<int> ret(n);
    iota(all(ret), 0);
    return ret;
}
template<typename T> vector<int> iota(const vector<T> &a, bool greater = false){
    vector<int> ret = iota(sz(a));
    sort(all(ret), [&](int i, int j){
        return (a[i] < a[j])^greater;
    });
    return ret;
}
struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;
#define VEC(type, name, n) vector<type> name(n); vin(name)
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
const int MOD = 1000000007;
//const int MOD = 998244353;

template<int char_size, char base>
struct Trie{
    struct Node{
        vector<int> next, accept;
        int count; //

        Node() : count(0){
            next.assign(char_size, -1);
        }
    };

    vector<Node> nodes;

    Trie() {nodes.eb();}

    int count() const {return nodes.front().count;}

    int size() const {return sz(nodes);}

    void insert(const string &s, int id){
        int now = 0;
        rep(i, sz(s)){
            int &next = nodes[now].next[s[i]-base];
            if(next == -1){
                next = size(), nodes.eb();
            }
            nodes[now].count++, now = next;
        }
        nodes[now].count++, nodes[now].accept.pb(id);
    }

    void insert(const string &s) {insert(s, count());}

    bool search(const string &s, bool prefix = false) const{
        int now = 0;
        rep(i, sz(s)){
            now = nodes[now].next[s[i]-base];
            if(now == -1) return false;
        }
        return (prefix)? true : !nodes[now].accept.empty();
    }
};

template<int char_size, char base>
struct Aho_Corasick : Trie<char_size+1, base>{
    const int FAIL = char_size;
    vector<int> correct;

    void build(bool heavy = true){
        correct.resize(this->size());
        rep(i, this->size()){
            correct[i] = sz(this->nodes[i].accept);
        }
        queue<int> que;
        rep(i, char_size+1){
            if(this->nodes[0].next[i] != -1){
                this->nodes[this->nodes[0].next[i]].next[FAIL] = 0;
                que.push(this->nodes[0].next[i]);
            }
            else{
                this->nodes[0].next[i] = 0;
            }
        }
        while(!que.empty()){
            auto &now = this->nodes[que.front()];
            int fail = now.next[FAIL];
            correct[que.front()] += correct[fail];
            que.pop();
            rep(i, char_size){
                if(now.next[i] != -1){
                    this->nodes[now.next[i]].next[FAIL] = this->nodes[fail].next[i];
                    if(heavy){
                        auto &u = this->nodes[now.next[i]].accept;
                        auto &v = this->nodes[this->nodes[fail].next[i]].accept;
                        vector<int> accept;
                        set_union(all(u), all(v), back_inserter(accept));
                        u = accept;
                    }
                    que.emplace(now.next[i]);
                }
                else{
                    now.next[i] = this->nodes[fail].next[i];
                }
            }
        }
    }

    map<int, int> match(int now, const string &s) const{
        map<int, int> ret;
        for(auto &c: s){
            now = this->nodes[now].next[c-base];
            for(auto &u: this->nodes[now].accept) ret[u]++;
        }
        return ret;
    }

    map<int, int> match(const string &s) const {return match(0, s);}

    pli move(int now, const char &c) const{
        now = this->nodes[now].next[c-base];
        return pli(correct[now], now);
    }

    pli move(const char &c) const {return move(0, c);}

    pli move(int now, const string &s) const{
        ll sum = 0;
        for(auto &c: s){
            pli p = move(now, c);
            sum += p.first, now = p.second;
        }
        return pli(sum, now);
    }

    pli move(const string &s) const {return move(0, s);}
};

int main(){
    INT(N, Q);
    map<string, int> mp;
    VEC(string, S, N);

    rep(i, N) mp[S[i]] = i;
    vi id(N);
    rep(i, N) id[i] = mp[S[i]];

    Aho_Corasick<26, 'a'> aho;
    each(e, mp) aho.insert(e.first, e.second);
    aho.build();

    vi now(N, 0);
    vector<map<int, int>> mp2(N);
    rep(i, N) mp2[id[i]][now[i]]++;
    vi MAX(N, 0);
    vi query;

    while(Q--){
        INT(q);
        if(q == 2){
            STR(T);
            int ptr = 0, M = sz(T), ans = -1;
            rep(i, M){
                ptr = aho.move(ptr, T[i]).second;
                auto node = aho.nodes[ptr];
                each(e, node.accept) chmax(ans, MAX[e]);
            }
            query.eb(ans);
        }
        else{
            INT(i, x); i--;
            if(--mp2[id[i]][now[i]] == 0) mp2[id[i]].erase(now[i]);
            mp2[id[i]][now[i] = x]++;
            MAX[id[i]] = (*mp2[id[i]].rbegin()).first;
        }
    }

    voutn(query);
}