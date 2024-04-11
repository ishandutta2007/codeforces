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

const int N = 3e2 + 5, M = 1e3 + 5, Q = 2e6 + 5;

struct Query{
    int x, y, c;
    
    Query(int x = 0, int y = 0, int c = 0): x(x), y(y), c(c){
        
    }
};

int n, m, q;
Query queries[Q];

int ans[Q];
int a[N][N], l[Q], r[Q];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool ck[N][N];
struct DisjointSetUnion{
    int par[N * N];
    
    void reset(){
        ForE(i, 1, n * m){
            par[i] = -1;
        }
    }
    
    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }
    
    bool merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return 0;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return 1;
    }
} dsu;
vi queriesdel[Q];

int cnv(int x, int y){
    return (x - 1) * m + y;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    ForE(i, 1, q){
        cin >> queries[i].x >> queries[i].y >> queries[i].c;
        if (a[queries[i].x][queries[i].y] != queries[i].c){
            queriesdel[a[queries[i].x][queries[i].y]].push_back(i);
        }
        a[queries[i].x][queries[i].y] = queries[i].c;
        if (!l[queries[i].c]){
            l[queries[i].c] = i;
        }
        r[queries[i].c] = i;
    }
    dsu.reset();
    ForE(c, 1, queries[q].c){
        if (!l[c]){
            continue;
        }
        ForE(i, l[c], r[c]){
            if (ck[queries[i].x][queries[i].y]){
                continue;
            }
            int dif = 1;
            ck[queries[i].x][queries[i].y] = 1;
            For(j, 0, 4){
                int tx = queries[i].x + dx[j], ty = queries[i].y + dy[j];
                if (ck[tx][ty] && dsu.merge(cnv(queries[i].x, queries[i].y), cnv(tx, ty))){
                    dif--;
                }
            }
            ans[i] += dif;
        }
        dsu.reset();
        Fora(&i, queriesdel[c]){
            ck[queries[i].x][queries[i].y] = 0;
        }
        ForE(i, 1, n){
            ForE(j, 1, m){
                if (ck[i][j] && ck[i - 1][j]){
                    dsu.merge(cnv(i, j), cnv(i - 1, j));
                }
                if (ck[i][j] && ck[i][j - 1]){
                    dsu.merge(cnv(i, j), cnv(i, j - 1));
                }
            }
        }
        reverse(bend(queriesdel[c]));
        Fora(&i, queriesdel[c]){
            int dif = 1;
            ck[queries[i].x][queries[i].y] = 1;
            For(j, 0, 4){
                int tx = queries[i].x + dx[j], ty = queries[i].y + dy[j];
                if (ck[tx][ty] && dsu.merge(cnv(queries[i].x, queries[i].y), cnv(tx, ty))){
                    dif--;
                }
            }
            ans[i] -= dif;
        }
        dsu.reset();
        ForE(i, l[c], r[c]){
            ck[queries[i].x][queries[i].y] = 0;
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            ck[i][j] = 1;
        }
    }
    ans[0] = 1;
    Fora(&i, queriesdel[0]){
        ck[queries[i].x][queries[i].y] = 0;
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (ck[i][j] && ck[i - 1][j]){
                dsu.merge(cnv(i, j), cnv(i - 1, j));
            }
            if (ck[i][j] && ck[i][j - 1]){
                dsu.merge(cnv(i, j), cnv(i, j - 1));
            }
        }
    }
    reverse(bend(queriesdel[0]));
    Fora(&i, queriesdel[0]){
        int dif = 1;
        ck[queries[i].x][queries[i].y] = 1;
        For(j, 0, 4){
            int tx = queries[i].x + dx[j], ty = queries[i].y + dy[j];
            if (ck[tx][ty] && dsu.merge(cnv(queries[i].x, queries[i].y), cnv(tx, ty))){
                dif--;
            }
        }
        ans[i] -= dif;
    }
    ForE(i, 1, q){
        ans[i] += ans[i - 1];
        cout << ans[i] << endl;
    }
}