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

int find_multiples(int x){
    cout << "A " << x << endl;
    int y;
    cin >> y;
    return y;
}

int find_delete_multiples(int x){
    assert(x > 1);
    cout << "B " << x << endl;
    int y;
    cin >> y;
    return y;
}

void answer(int x){
    cout << "C " << x << endl;
}

int count_div(vi &rem, int n, int div){
    int ans = 0;
    for(int i = div; i <= n; i+=div){
        ans += rem[i];
    }
    return ans;
}

void del_div(vi &rem, int n, int div){
    for(int i = div; i <= n; i+=div){
        rem[i] = 0;
    }
}

const int B = 98;
// const int B = 2;

void solve(){
    int n;
    cin >> n;
    vi primes;
    vi is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
        if(is_prime[i] && i < 2000 && i*i <= n){ // overflow protection
            for(int j = i*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    int m = primes.size();
    debug(m);

    vi rem(n+1);
    for(int i = 1; i <= n; i++) rem[i] = 1;

    vi factors;

    int last_idx = -1;
    for(int i = 0; i < m; i+=B){
        int end = min(m, i+B);
        for(int j = i; j < end; j++){
            find_delete_multiples(primes[j]);
            del_div(rem, n, primes[j]);
        }
        int tot = find_multiples(1);
        if(count_div(rem, n, 1) != tot){
            for(int j = i; j < end; j++){
                int occ = find_multiples(primes[j]);
                if(occ > 0){
                    factors.push_back(primes[j]);
                }
            }
            last_idx = end;
            break;
        }
    }
    if(last_idx == -1){
        answer(1);
        return;
    }
    for(int i = last_idx; i < m; i++){
        int occ = find_delete_multiples(primes[i]);
        if(occ > count_div(rem, n, primes[i])){
            factors.push_back(primes[i]);
        }
        del_div(rem, n, primes[i]);
    }
    debug(factors);
    int ans = 1;
    for(int i : factors){
        int cur = i;
        while((ll) cur*i <= (ll) n){
            int occ = find_multiples(cur*i);
            if(occ > 0){
                cur *= i;
            }else{
                break;
            }
        }
        ans *= cur;
    }
    answer(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}