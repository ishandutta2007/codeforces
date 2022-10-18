#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vvi trans(vvi &v){
    vvi res(v[0].size(), vi(v.size()));
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            res[j][i] = v[i][j];
        }
    }
    return res;
}

void ans(vvi &mat, bool transposed){
    if(transposed){
        mat = trans(mat);
    }
    cout << "YES\n";
    for(vi &v : mat){
        for(int &x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi mat(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = i*m+j+1;
        }
    }
    bool transposed = false;
    if(n > m){
        transposed = true;
        swap(n, m);
        mat = trans(mat);
    }
    if(m < 4){
        if(n == 3 && m == 3){
            cout << "YES\n6 1 8\n7 5 3\n2 9 4\n";
        }else if(n == 1 && m == 1){
            cout << "YES\n1\n";
        }else{
            cout << "NO\n";
        }
        return;
    }
    if(m == 4 && n >= 2){
        if(transposed){
            mat = trans(mat);
            transposed = false;
            swap(n, m);
        }
        if(n == 2 && m == 4){
            cout << "YES\n1 8 3 6\n7 2 5 4\n";
        }else if(n == 3 && m == 4){
            cout << "YES\n1 10 3 12\n7 2 5 4\n9 8 11 6\n";
        }else if(n == 4 && m == 4){
            cout << "YES\n1 8 3 6\n7 2 5 4\n9 16 11 14\n15 10 13 12\n";
        }else if(n == 4 && m == 3){
            cout << "YES\n1 8 3\n6 4 11\n7 2 9\n12 10 5\n";
        }else if(n == 4 && m == 2){
            cout << "YES\n1 6\n8 3\n5 2\n4 7\n";
        }
        return;
    }
    vi below(n*m+1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            below[mat[(i+1)%n][j]] = mat[i][j];
        }
    }
    debug(below);

    vvi res(n);
    for(int i = 0; i*2+1 < m; i++){
        res[0].push_back(mat[0][i*2+1]);
    }
    for(int i = 0; i*2 < m; i++){
        res[0].push_back(mat[0][i*2]);
    }
    
    // TODO m=4
    for(int i = 1, dir = -1; i < n; i++, dir*=-1){
        for(int j = 0; j < m; j++){
            // debug(i, j, res[i-1][(j+1)%m],below[res[i-1][(j+1)%m]]);
            res[i].push_back(below[res[i-1][(j+dir+m)%m]]);
        }
    }
    ans(res, transposed);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}