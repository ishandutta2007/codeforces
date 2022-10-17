#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
struct Fenwick{
    vector<T> v;
    Fenwick(int N){ v.resize(N); }
    void ins(int i, T val){
        for (; i < v.size(); i += i & -i) v[i] += val;
    }
    T qry(int i){
        T ret(0);
        for (; i; i -= i & -i) ret += v[i];
        return ret;
    }
    T qry(int l, int r){
        return qry(r) - qry(l - 1);
    }
};

mt19937_64 gen;
ll randint(){
    return uniform_int_distribution<ll>(1, 2e13)(gen);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int B = 35;
    int N, Q; cin >> N >> Q;
    unordered_map<int, vector<ll>> mp;
    auto newkey = [&](int a){
        vector<ll> h(B);
        for (int i = 0; i < B; ++i){
            h[i] = randint();
        }
        mp[a] = h;
    };
    vector<int> a(N+1);
    vector<Fenwick<ll>> bit(B, Fenwick<ll>(N+1));
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        if (!mp.count(a[i])) newkey(a[i]);
        for (int b = 0; b < B; ++b){
            bit[b].ins(i, mp[a[i]][b]);
        }
    }
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int i, x; cin >> i >> x;
            if (!mp.count(x)) newkey(x);
            for (int b = 0; b < B; ++b){
                bit[b].ins(i, mp[x][b]-mp[a[i]][b]);
            }
            a[i] = x;
        }
        if (op == 2){
            int l, r, k; cin >> l >> r >> k;
            bool ans = 1;
            for (int b = 0; b < B; ++b){
                ans &= bit[b].qry(l, r) % k == 0;
            }
            cout << (ans ? "YES" : "NO") << '\n';
        }
    }
}