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

int query(int l, int r){
    cout << "? " << l+1 << " " << r+1 << endl;
    int x;
    cin >> x;
    if(x == -1){
        exit(0);
    }
    return x;
}

void answer(int index){
    cout << "! " << index + 1 << endl;
    // int x;
    // cin >> x;
    // if(x == -1){
    //     exit(0);
    // }
}

void st_set(vi &st, int tl, int tr, int pos, int p, int value){
    if(tl == tr){
        st[pos] = value;
        return;
    }
    if(p <= tl + (tr - tl) / 2){
        st_set(st, tl, tl + (tr - tl) / 2, pos * 2, p, value);
    }
    else{
        st_set(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, p, value);
    }
    st[pos] = st[2 * pos] + st[2 * pos + 1];
}

int st_sum(vi &st, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left) return 0;
    if(left <= tl && tr <= right){
        return st[pos];
    }
    return st_sum(st, tl, tl + (tr - tl) / 2, pos * 2, left, right) + st_sum(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
}

const int CHUNK_SIZE = 16;

void solve(){
    int n, t;
    cin >> n >> t;
    int chunks = (n - 1) / CHUNK_SIZE + 1;
    vi v(chunks);
    vi st(4 * chunks);
    for(int tt = 0; tt < t; tt++){
        int k;
        cin >> k;
        if(tt == 0){
            for(int i = 0; i < chunks; i++){
                int x = query(i*CHUNK_SIZE, min(n-1, (i+1)*CHUNK_SIZE - 1));
                v[i] = x;
                st_set(st, 0, chunks-1, 1, i, x);
            }
            debug(v);
        }
        int left = 0, right = chunks-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            int interval = (mid == chunks-1 ? n : (mid+1) * 16);
            int res = st_sum(st, 0, chunks-1, 1, 0, mid);
            int zeros = interval - res;
            debug(left, right, mid, res, interval, zeros);
            if(zeros >= k){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        int chunk = left;
        v[chunk]++;
        st_set(st, 0, chunks-1, 1, chunk, v[chunk]);
        left = chunk * 16;
        right = min(n-1, left + 15);
        while(left < right){
            int mid = left + (right - left) / 2;
            int res = query(0, mid);
            int zeros = (mid + 1) - res;
            if(zeros >= k){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        answer(left);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}