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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vi perm;

ll isqrt(ll n){
    ll x = n;
    ll y = (x + 1) >> 1;
    while(y < x){
        x = y;
        y = (x + n / x) >> 1;
    }
    return x;
}

ll query(int a, int b){
    cout << "? " << perm[a]+1 << ' ' << perm[b]+1 << endl;
    ll x;
    cin >> x;
    return x;
}

void answer(vi &v){
    vi ans(v.size());
    for(int i = 0; i < v.size(); i++){
        ans[perm[i]] = v[i];
    }
    cout << '!';
    for(int i : ans){
        cout << ' ' << i;
    }
    cout << endl;
}

const int C = 500;
const int N = 2e5 + 5;
vi pr;
vi lp(N);

void precomp(){
    for(int i = 2; i < N; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && i * pr[j] < N && pr[j] <= lp[i]; j++){
            lp[i*pr[j]] = pr[j];
        }
    }
    debug(pr.size());
}

ll greatest_prime(ll x){
    assert(x < (ll) N * N);
    ll ans = 1;
    auto it = pr.begin();
    while(x > N && it != pr.end()){
        if(x % *it == 0){
            ans = max(ans, (ll) *it);
            x /= *it;
        }else{
            it++;
        }
    }
    if(it == pr.end()){
        return x;
    }
    while(x > 1){
        ans = max(ans, (ll) lp[x]);
        x /= lp[x];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    perm.resize(n);
    for(int i = 0; i < n; i++) perm[i] = i;
    shuffle(perm.begin(), perm.end(), rng);
    if(n < 100){
        vvll res(n, vll(n));
        set<pair<ll, pii>> s;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                res[i][j] = res[j][i] = query(i, j);
                s.insert({res[i][j], {i, j}});
                s.insert({res[j][i], {j, i}});
            }
        }
        vi ans(n);
        int lst;
        set<int> left;
        for(int i = 0; i < n; i++) left.insert(i);
        while(!s.empty()){
            auto maxi = *prev(s.end());
            int c1, c2;
            tie(c1, c2) = maxi.second;
            int sq = isqrt(maxi.first) + 1; // = value of bigger number
            lst = sq;
            debug(maxi.first, sq);
            bool ok = true;
            for(int i = 0; i < n; i++){
                if(res[c1][i] % sq != 0){
                    ok = false;
                    break;
                }
            }
            int idx = ok ? c1 : c2;
            ans[idx] = sq;
            left.erase(idx);
            for(int i = 0; i < n; i++){
                s.erase({res[idx][i], {idx, i}});
                s.erase({res[idx][i], {i, idx}});
            }
        }
        ans[*left.begin()] = lst - 1;
        answer(ans);
    }else if(n < 9900){
        int maxp = 0;
        int maxi;
        for(int i = 0; i < n; i+=2){
            if(i == n-1){
                i--;
            }
            ll res = query(i, i+1);
            ll gp = greatest_prime(res);
            if(gp > maxp){
                maxp = gp;
                maxi = i;
            }
        }
        int idx = maxi;
        ll gp = greatest_prime(query(idx, (idx+2)%n));
        if(gp != maxp){
            idx++;
        }
        vi ans(n);
        ans[idx] = maxp;
        for(int i = 0; i < n; i++){
            if(i == idx) continue;
            ll res = query(i, idx);
            ans[i] = res / maxp;
        }
        answer(ans);
    }else{
        int idx1, idx2;
        int p1, p2;
        while(true){
            idx1 = rng() % n, idx2 = rng() % n;
            if(idx1 == idx2) continue;
            ll res = query(idx1, idx2);
            p1 = greatest_prime(res);
            if(p1 < C) continue;
            p2 = res / p1;
            if(p2 >= N || p2 < C || lp[p2] != p2) continue;
            break;
        }
        bool ok = true;
        for(int i = 0; i < 60; i++){
            int other;
            do{
                other = rng() % n;
            }while(other == idx1);
            ll res = query(idx1, other);
            if(res % p1 != 0){
                ok = false;
                break;
            }
        }
        if(!ok){
            swap(p1, p2);
        }

        vi ans(n);
        ans[idx1] = p1;
        ans[idx2] = p2;
        int maxp = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(i == idx1 || i == idx2) continue;
            ll res = query(idx1, i);
            ll cand = res / p1;
            if(cand > C){
                ans[i] = cand;
                if(lp[cand] == cand && cand > maxp){
                    maxp = cand;
                    maxi = i;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(ans[i] != 0) continue;
            ll res = query(i, maxi);
            ans[i] = res / maxp;
        }
        answer(ans);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}