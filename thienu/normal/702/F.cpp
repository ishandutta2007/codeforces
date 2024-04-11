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

const int B = 31;
// const int B = 5;

struct Customer{
    ll money;
    int idx;
    int times;
    Customer(ll _money, int _idx, int _times) : money(_money), idx(_idx), times(_times) {}
};
void __print(Customer x) {cerr << '{' << x.money << ',' << x.idx << ',' << x.times << '}';}

bool operator<(Customer a, Customer b){
    return a.money < b.money || (a.money == b.money && a.idx < b.idx);
}

struct Bucket{
    set<Customer> customers;
    ll reduce = 0;
    int extra_times = 0;
    int idx;
    Bucket(int _idx) : idx(_idx) {}

    ll lo(){
        return (1LL<<(idx-1));
    }

    ll hi(){
        return (1LL<<idx);
    }

    pair<ll, ll> bounds(){
        return {lo(), hi()};
    }

    void take_money(ll money){
        reduce += money;
        extra_times++;
    }
    
    void out_of_bucket(vector<Customer> &res){
        debug(idx, lo());
        while(!customers.empty() && customers.begin()->money - reduce < lo()){
            res.push_back(Customer(customers.begin()->money - reduce, customers.begin()->idx, customers.begin()->times + extra_times));
            customers.erase(customers.begin());
        }
    }

    void lower_bound(ll cost, vector<Customer> &res){
        while(!customers.empty() && prev(customers.end())->money - reduce >= cost){
            res.push_back(Customer(prev(customers.end())->money - reduce, prev(customers.end())->idx, prev(customers.end())->times + extra_times));
            customers.erase(prev(customers.end()));
        }
    }

    void add_customer(Customer c){
        customers.insert({c.money + reduce, c.idx, c.times - extra_times});
    }
};
void __print(Bucket x) {cerr << "{{"; for(Customer c : x.customers){__print(c);cerr<<',';}cerr<<"},"<<x.reduce<<','<<x.extra_times<<'}';}

int get_bucket(ll money){
    if(money == 0) return 0;
    return 8 * sizeof(ll) - __builtin_clzll(money);
}

void solve(){
    int n;
    cin >> n;
    vpii shirts(n);
    for(int i = 0; i < n; i++){
        int c, q;
        cin >> c >> q;
        shirts[i] = {-q, c};
    }
    sort(shirts.begin(), shirts.end());
    vll costs;
    for(pii p : shirts){
        costs.push_back(p.second);
    }
    debug(costs);

    vector<Bucket> buckets;
    for(int i = 0; i < B; i++){
        buckets.push_back(Bucket(i));
    }
    // debug(buckets[0].bounds(), buckets[29].bounds());
    // debug(get_bucket(0), get_bucket(1), get_bucket(2), get_bucket(3));
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        ll money;
        cin >> money;
        // debug(get_bucket(money));
        buckets[get_bucket(money)].add_customer(Customer(money, i, 0));
    }

    for(ll cost : costs){
        debug(buckets);
        int bucket = get_bucket(cost);
        // debug("a");
        vector<Customer> res;
        buckets[bucket].lower_bound(cost, res);
        vector<Customer> reassign;
        for(Customer c : res){
            reassign.push_back(Customer(c.money - cost, c.idx, c.times + 1));
        }
        debug(reassign);
        for(int b = bucket+1; b < B; b++){
            buckets[b].take_money(cost);
            buckets[b].out_of_bucket(reassign);
        }
        debug(reassign);
        for(Customer c : reassign){
            buckets[get_bucket(c.money)].add_customer(c);
        }
    }
    debug(buckets);

    vi ans(m);
    for(int b = 0; b < B; b++){
        for(Customer c : buckets[b].customers){
            ans[c.idx] = c.times + buckets[b].extra_times;
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}