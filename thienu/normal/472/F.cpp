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

int clz(int x){
    if(x == 0) return 32;
    else return __builtin_clz(x);
}

const int B = 30;

vi basis(vi &v){
    int n = v.size();
    vi out;
    for(int i : v){
        for(auto it = out.begin(); it != out.end(); it++){
            int j = *it;
            if(clz(i) < clz(j)){
                out.insert(it, i);
                goto basis_done;
            }else if(clz(i) == clz(j)){
                i ^= j;
            }
        }
        if(i != 0){
            out.push_back(i);
        }
        basis_done:
        ;
    }
    return out;
}

int convert_basis(int x, vi &basis){
    debug(x);
    int out = 0;
    for(int i = 0; i < basis.size(); i++){
        if(clz(x) == clz(basis[i])){
            out |= (1<<i);
            x ^= basis[i];
        }
    }
    if(x != 0) return -1;
    return out;
}

vpii reduce_to_basis(vi &v, int sz){
    int n = v.size();
    vpii res;
    for(int i = 0; i < sz; i++){
        if(((v[i] >> i) & 1) ^ 1){
            for(int j = i+1; j < n; j++){
                if((v[j] >> i) & 1){
                    res.push_back({i, j});
                    v[i] ^= v[j];
                    break;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if((v[j] >> i) & 1){
                res.push_back({j, i});
                v[j] ^= v[i];
            }
        }
    }
    debug(v);
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vi ba = basis(a);
    debug(ba);
    for(int i : b){
        if(convert_basis(i, ba) == -1){
            cout << -1 << endl;
            return;
        }
    }
    // int baor = 0;
    // for(int i : ba){
    //     baor |= i;
    // }
    // for(int i : b){
    //     if((baor | i) != baor){
    //         cout << -1 << endl;
    //         return;
    //     }
    // }
    for(int &i : a) i = convert_basis(i, ba);
    for(int &i : b) i = convert_basis(i, ba);
    debug(a, b);

    // debug(reduce_to_basis(a, ba.size()));
    vpii op1 = reduce_to_basis(a, ba.size());
    vpii op2 = reduce_to_basis(b, ba.size());
    debug(op1, op2);
    for(int i = 0; i < ba.size(); i++){
        if(b[i] == 0){
            op1.push_back({i, i});
            a[i] ^= a[i];
        }
        for(int j = i+1; j < ba.size() && a[i] != b[i]; j++){
            if(a[j] & b[i]){
                op1.push_back({i, j});
                a[i] ^= a[j];
            }
        }
    }
    cout << op1.size() + op2.size() << '\n';
    for(pii p : op1){
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
    reverse(op2.begin(), op2.end());
    for(pii p : op2){
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}