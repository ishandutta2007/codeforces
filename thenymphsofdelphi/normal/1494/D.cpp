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

// juckter quest

typedef tuple <int, int, int> iii;

const int N = 5e2 + 5, M = 3e5 + 5;

struct DisjointSetUnion{
    int par[N], top[N];
    
    DisjointSetUnion(int n){
        ForE(i, 1, n){
            par[i] = -1;
            top[i] = i;
        }
    }
    
    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }
    
    void merge(int x, int y, int z){
        if ((x = root(x)) == (y = root(y))){
            return;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        top[x] = z;
    }
};

int n;
int a[N][N];

int k;
int c[M];
vpii vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cin >> a[i][j];
        }
    }
    DisjointSetUnion dsu(n);
    priority_queue <iii, vector <iii>, greater <iii>> pq;
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (i == j){
                c[++k] = a[i][j];
            }
            else{
                pq.push(make_tuple(a[i][j], i, j));
            }
        }
    }
    while (!pq.empty()){
        int val = get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top()); pq.pop();
        x = dsu.root(x); y = dsu.root(y);
        if (x == y){
            continue;
        }
        if (c[dsu.top[x]] == val){
            vans.emplace_back(dsu.top[y], dsu.top[x]);
            dsu.merge(x, y, dsu.top[x]);
            continue;
        }
        if (c[dsu.top[y]] == val){
            vans.emplace_back(dsu.top[x], dsu.top[y]);
            dsu.merge(x, y, dsu.top[y]);
            continue;
        }
        c[++k] = val;
        vans.emplace_back(dsu.top[x], k);
        vans.emplace_back(dsu.top[y], k);
        dsu.merge(x, y, k);
    }
    cout << k << endl;
    ForE(i, 1, k){
        cout << c[i] << ' ';
    } cout << endl;
    cout << k << endl;
    Fora(&v, vans){
        cout << v.fi << ' ' << v.se << endl;
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