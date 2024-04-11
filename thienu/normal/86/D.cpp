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

int BUCKET_SIZE = 500;
// int BUCKET_SIZE = 3;
int MAX_NUM = 1e6 + 5;


int comp(pair<pii, int> a, pair<pii, int> b){
    // does a go before b?
    pii p = a.first, q = b.first;
    int pb = p.first / BUCKET_SIZE;
    int qb = q.first / BUCKET_SIZE;
    if(pb != qb){
        return pb < qb;
    }
    return p.second < q.second;
}

void add(int num, vi &freq, ll &ans){
    debug("add", num, (2 * freq[num] + 1) * num);
    ans += (ll) (2 * freq[num] + 1) * num;
    freq[num]++;
}

void rem(int num, vi &freq, ll &ans){
    debug("rem", num, (2 * freq[num] - 1) * num);
    ans -= (ll) (2 * freq[num] - 1) * num;
    freq[num]--;
}

void move(int &left, int &right, int nl, int nr, vi &v, vi &freq, ll &ans){
    // move left
    if(left < nl){
        for(int i = left; i < nl; i++){
            rem(v[i], freq, ans);
        }
    }
    else if(nl < left){
        for(int i = left - 1; i >= nl; i--){
            add(v[i], freq, ans);
        }
    }

    // move right
    if(right < nr){
        for(int i = right + 1; i <= nr; i++){
            add(v[i], freq, ans);
        }
    }
    else if(nr < right){
        for(int i = right; i > nr; i--){
            rem(v[i], freq, ans);
        }
    }

    left = nl;
    right = nr;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<pair<pii, int>> queries(q);
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        queries[i] = make_pair(make_pair(x, y), i);
    }
    sort(queries.begin(), queries.end(), comp);
    debug(queries);
    vi freq(MAX_NUM);
    int left = 0;
    int right = 0;
    freq[v[0]]++;
    ll ans = v[0];

    vll qans(q);
    for(int i = 0; i < q; i++){
        int qn;
        pii p;
        tie(p, qn) = queries[i];
        move(left, right, p.first, p.second, v, freq, ans);
        qans[qn] = ans;
        debug("done", i, ans, qn, left, right);
    }
    debug(qans);

    for(ll i : qans){
        cout << i << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}