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

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll normalize(ll x){
    return ((x % MOD) + MOD) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

const int A = 2e5 + 5;
const int L = 450;
vi lp(A), pr;

void precomp(){
    for(int i = 2; i < A; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && i * pr[j] < A && pr[j] <= lp[i]; j++){
            lp[i * pr[j]] = pr[j];
        }
    }
}

vpii merge_pii(vpii &a, vpii &b){
    vpii out;
    auto it1 = a.begin(), it2 = b.begin();
    while(it1 != a.end() || it2 != b.end()){
        if(it1 == a.end()){
            out.push_back(*it2);
            it2++;
        }else if(it2 == b.end()){
            out.push_back(*it1);
            it1++;
        }else if(it1->first == it2->first){
            out.push_back({it1->first, max(it1->second, it2->second)});
            it1++;
            it2++;
        }else if(it1->first < it2->first){
            out.push_back(*it1);
            it1++;
        }else{
            out.push_back(*it2);
            it2++;
        }
    }
    return out;
}

vi big_prime;
vi last;

struct Node{
    Node* l;
    Node* r;
    int lo, hi;
    vpii small;
    vpii big;
    vll prod;
    Node(vi &a, int lo, int hi) : lo(lo), hi(hi) {
        if(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;
            l = new Node(a, lo, mid);
            r = new Node(a, mid, hi);
            merge(l->big.begin(), l->big.end(), r->big.begin(), r->big.end(), back_inserter(big));
            small = merge_pii(l->small, r->small);
        }else{
            int val = a[lo];
            for(int p : pr){
                if(p > L) break;
                int m = 0;
                while(val % p == 0){
                    val /= p;
                    m++;
                }
                if(m){
                    small.push_back({p, m});
                }
            }
            if(val > 1){
                big.push_back({last[lo], val});
            }
        }
        prod.push_back(1);
        ll product = 1;
        for(pii p : big){
            product = mul(product, p.second);
            prod.push_back(product);
        }
    }

    pair<ll, vpii> get(int left, int right){
        if(right <= lo || hi <= left){
            return {1, {}};
        }
        if(left <= lo && hi <= right){
            auto it = lower_bound(big.begin(), big.end(), make_pair(left, -1));
            // auto it = big.begin();
            int idx = it - big.begin();
            return {prod[idx], small};
        }
        vpii s1, s2;
        ll b1, b2;
        tie(b1, s1) = l->get(left, right);
        tie(b2, s2) = r->get(left, right);
        return {mul(b1, b2), merge_pii(s1, s2)};
    }

    ll query(int left, int right){
        vpii s;
        ll b;
        tie(b, s) = get(left, right);
        ll ans = b;
        for(pii p : s){
            ans = mul(ans, binexp(p.first, p.second));
        }
        return ans;
    }
};

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++){
        int val = v[i];
        for(int p : pr){
            if(p > L) break;
            while(val % p == 0) val /= p;
        }
        big_prime.push_back(val);
    }
    map<int, int> tmp;
    for(int i = 0; i < n; i++){
        last.push_back(tmp[big_prime[i]]-1);
        if(big_prime[i] > 1) tmp[big_prime[i]] = i+1;
    }
    debug(last);

    Node* root = new Node(v, 0, n);
    debug(root->big);
    debug(root->small);
    debug(root->prod);

    int q;
    cin >> q;
    int last = 0;
    while(q--){
        int x, y;
        cin >> x >> y;
        int l = (x+last)%n;
        int r = (y+last)%n;
        if(r < l) swap(l, r);
        r++;
        last = root->query(l, r);
        cout << last << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    solve();
    return 0;
}