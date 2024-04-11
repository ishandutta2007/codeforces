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

template <int N>
struct Vec{
    vi v;

    Vec(){
        v.resize(N);
    }

    Vec<N> operator+(Vec<N> other){
        Vec<N> nv;
        for(int i = 0; i < N; i++){
            nv.v[i] = v[i] + other.v[i];
        }
        return nv;
    }
    Vec<N> operator-(Vec<N> other){
        Vec<N> nv;
        for(int i = 0; i < N; i++){
            nv.v[i] = v[i] - other.v[i];
        }
        return nv;
    }
    Vec<N> operator*(int s){
        Vec<N> nv;
        for(int i = 0; i < N; i++){
            nv.v[i] = v[i] * s;
        }
        return nv;
    }

    int sum(){
        return accumulate(v.begin(), v.end(), 0);
    }

    vi nonzero(){
        vi ans;
        for(int i = 0; i < N; i++){
            if(v[i] != 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
template <int N>
void __print(Vec<N> x) {_print(x.v);}

const int A = 26;

vector<Vec<A>> query(int l, int r){
    cout << "? " << l+1 << ' ' << r+1 << endl;
    vector<Vec<A>> out;
    for(int i = 0; i < (r-l+1) * (r-l+2) / 2; i++){
        string s;
        cin >> s;
        if(s == "-"){
            exit(0);
        }
        Vec<A> v;
        for(char c : s){
            v.v[c-'a']++;
        }
        out.push_back(v);
    }
    debug(out);
    return out;
}

void get_pairing(int l, int r, vector<vector<pair<int, pii>>> &pairing, vi &ans){
    if(r < l) return;
    int m = r-l+1;
    vector<Vec<A>> q = query(l, r);
    debug(q);
    vector<Vec<A>> size_sum(m+1);
    for(Vec<A> v : q){
        size_sum[v.sum()] = size_sum[v.sum()] + v;
    }
    debug(size_sum);

    vector<Vec<A>> pairing_sum((m+1)/2);
    for(int i = 0; i < (m+1)/2; i++){
        if(l+i == r-i){
            Vec<A> x = size_sum[m];
            for(int j = 0; j < i; j++){
                x = x - pairing_sum[j];
            }
            pairing_sum[i] = x;
            break;
        }
        Vec<A> p = size_sum[m] * (i+2);
        Vec<A> q = size_sum[m-i-1];
        Vec<A> diff = p-q;
        for(int j = 0; j < i; j++){
            diff = diff - pairing_sum[j] * (i+1-j); 
        }
        pairing_sum[i] = diff;
    }
    debug(pairing_sum);
    for(int i = 0; i < (m+1)/2; i++){
        if(l+i == r-i){
            ans[l+i] = pairing_sum[i].nonzero()[0];
        }else{
            vi nz = pairing_sum[i].nonzero();
            if(nz.size() == 1){
                ans[l+i] = pairing_sum[i].nonzero()[0];
                ans[r-i] = pairing_sum[i].nonzero()[0];
            }else{
                pairing[l+i].push_back({r-i, {pairing_sum[i].nonzero()[0], pairing_sum[i].nonzero()[1]}});
                pairing[r-i].push_back({l+i, {pairing_sum[i].nonzero()[0], pairing_sum[i].nonzero()[1]}});
            }
        }
    }
}

void answer(vi &ans){
    cout << "! ";
    for(int i : ans){
        cout << (char)('a'+i);
    }
    cout << endl;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<pair<int, pii>>> pairing(n);
    vi ans(n, -1);
    get_pairing(0, n-1, pairing, ans);
    if(n & 1){
        get_pairing(0, n/2, pairing, ans);
        get_pairing(n/2+1, n-1, pairing, ans);
    }else{
        get_pairing(0, n/2, pairing, ans);
        get_pairing(n/2, n-1, pairing, ans);
    }
    debug(0, n/2, n/2+1, n-1);
    debug(pairing, ans);

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(ans[i] != -1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(pair<int, pii> p : pairing[u]){
            int v = p.first;
            if(ans[v] == -1){
                q.push(v);
                ans[v] = (p.second.first == ans[u] ? p.second.second : p.second.first);
            }
        }
    }
    for(int i = 0; i < n; i++){
        assert(ans[i] >= 0);
    }
    answer(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}