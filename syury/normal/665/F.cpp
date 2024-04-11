//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

template<ll mod>
inline ll add(ll x, ll y){
    x += y;
    return x >= mod ? x - mod : x;
}
template<ll mod>
inline void iadd(ll & x, ll y){
    x += y;
    x -= x >= mod ? mod : 0;
}
template<ll mod>
inline ll sub(ll x, ll y){
    x -= y;
    return x < 0 ? x + mod : x;
}
template<ll mod>
inline void isub(ll & x, ll y){
    x -= y;
    x += x < 0 ? mod : 0;
}
template<ll mod>
inline ll mul(ll x, ll y){
    return (x * y) % mod;
}
template<ll mod>
inline void imul(ll & x, ll y){
    x *= y;
    x %= mod;
}

template<ll mod>
inline ll modpow(ll a, ll n){
    ll result = 1;
    while(n){
        if(n&1)
            imul<mod>(result, a);
        imul<mod>(a, a);
        n >>= 1;
    }
    return result;
}
ll intpow(ll x, int pw){
    ll result = 1;
    while(pw){
        if(pw&1)
            result *= x;
        x *= x;
        pw >>= 1;
    }
    return result;
}
ll rounded_root(ll x, int pw){
    ll rt = ll(pow((long double)x, 1./pw));
    while(intpow(rt, pw) <= x)
        ++rt;
    return rt - 1;
}

template<ll mod>
struct ModularFenwick{
    vector<ll> t;
    int N;
    ModularFenwick(){}
    ModularFenwick(int _N):N(_N){
        t.resize(N);
    }
    inline void reset(){
        fill(t.begin(), t.end(), 0);
    }
    inline void add(int pos, ll val){
        while(pos <= N){
            iadd<mod>(t[pos], val);
            pos += pos&-pos;
        }
    }
    inline ll get(int pref){
        ll ans = 0;
        while(pref){
            iadd<mod>(ans, t[pref]);
            pref -= pref&-pref;
        }
        return ans;
    }
};

//1^k + ... + n^k in O(k log k)
template<ll mod>
struct PowerSum{
    int k;
    vector<ll> y;
    vector<ll> inv, ifac;
    vector<ll> forw, backw;
    PowerSum(int _k):k(_k){
        y = vector<ll>(k + 2, 0);
        for(int i = 1; i <= k + 1; i++){
            y[i] = y[i - 1];
            iadd<mod>(y[i], modpow<mod>(i, k));
        } 
        inv = vector<ll>(k + 2, 1);
        ifac = vector<ll>(k + 2, 1);
        for(int i = 2; i <= k + 1; i++){
            inv[i] = sub<mod>(0, mul<mod>(mod/i, inv[mod % i]));
            ifac[i] = mul<mod>(ifac[i - 1], inv[i]);
        }
        forw = vector<ll>(k + 2, 0);
        backw = vector<ll>(k + 2, 0);
    }
    ll eval(ll x){
        x %= mod;
        forw[0] = 1;
        for(int i = 1; i <= k + 1; i++){
            forw[i] = mul<mod>(forw[i - 1], sub<mod>(x, i - 1));
        }
        backw[k + 1] = 1;
        for(int i = k; i >= 0; i--){
            backw[i] = mul<mod>(backw[i + 1], sub<mod>(x, i + 1));
        }
        ll ans = 0;
        for(int i = 0; i <= k + 1; i++){
            ll curr = mul<mod>(y[i], mul<mod>(mul<mod>(forw[i], backw[i]), mul<mod>(ifac[i], ifac[k + 1 - i])));
            if((k + 1 - i)&1)
                curr = curr ? mod - curr : 0;
            iadd<mod>(ans, curr);
        }
        return ans;
    }
};

//calculates f(1) + ... + f(n) mod M, M is prime
//under the following assumptions:
//f is multiplicative
//f(p) = a_kp^k + ... + a_0
//it can also be used to calculate \sum\limits_{p=2}^n f(p) * I[p is prime]
template<ll mod>
struct MultiplicativeSum{
    using State = vector<ll>;
    ll n, sq, cb, root6;
    ll query_bound;
    vector<size_t> big;
    vector<ll> state_elements;
    vector<ll> primes; //1-indexed
    vector<ll> lp;
    vector<ll> pi;
    vector<ll> precalc_f;
    vector<ll> prime_powers;
    ModularFenwick<mod> t;
    ll (*func)(ll, ll) = nullptr;
    vector<ll> polynomial;
    State prime_full, all_full;
    MultiplicativeSum(ll (*_func)(ll, ll), //func(p, k) = f(p^k)
                      vector<ll> _polynomial //f(p) on prime p
            ):func(_func), polynomial(_polynomial){}
    inline ll f(ll p, ll k){
        return (*func)(p, k);
    }
    inline void sieve(ll sz){
        primes.push_back(0); //to ensure 1-indexing
        precalc_f.resize(sz + 1);
        lp.resize(sz + 1);
        lp.assign(sz + 1, 0ll);
        vector<ll> antilp(sz + 1, 0);
        vector<ll> lp_pow(sz + 1, 0);
        precalc_f[1] = 1;
        for(ll i = 2; i <= sz; i++){
            if(!lp[i]){
                lp[i] = i;
                lp_pow[i] = 1;
                precalc_f[i] = f(i, 1);
                antilp[i] = 1;
                primes.push_back(i);
            }
            for(size_t j = 1; j < primes.size() && primes[j] <= lp[i] && i * primes[j] <= sz; j++){
                ll k = i * primes[j];
                lp[k] = primes[j];
                lp_pow[k] = primes[j] == lp[i] ? lp_pow[i] + 1 : 1;
                antilp[k] = primes[j] == lp[i] ? antilp[i] : i;
                precalc_f[k] = 1 == antilp[k] ? f(lp[k], lp_pow[k]) :
                    mul<mod>(precalc_f[antilp[k]], precalc_f[k / antilp[k]]);
            }
        }
        pi.resize(sz + 1);
        pi.assign(sz + 1, 0ll);
        for(ll i = 2; i <= sz; i++){
            pi[i] = pi[i - 1];
            if(lp[i] == i)
                ++pi[i];
        }
    }
    inline size_t get_index(ll x){
        if(x <= sq)
            return x - 1;
        else
            return big[n/x];
    }
    State power1(State prv){
        State nxt(state_elements.size());
        for(int k = 1; k <= pi[root6] + 1; k++){
            nxt.assign(state_elements.size(), 0);
            ll mul_with = prime_powers[k];
            size_t ptr = 0;
            for(size_t i = 0; i < state_elements.size(); i++){
                ll m = state_elements[i]/primes[k];
                while(state_elements[ptr] < m)
                    ++ptr;
                nxt[i] = m ? sub<mod>(prv[i], mul<mod>(prv[ptr], mul_with)) : prv[i];
            }
            nxt.swap(prv);
        }
        return prv;
    }
    State power2(State prv, int coeff){
        t.reset();
        for(int k = pi[root6] + 2; k <= pi[cb] + 1; k++){
            size_t ptr = state_elements.size() - 1;
            size_t lptr = state_elements.size() - 1;
            ll mul_with = prime_powers[k];
            while(state_elements[ptr] >= query_bound){
                ll m = state_elements[ptr];
                ll m2 = m/primes[k];
                while(state_elements[lptr] > m2){
                    --lptr;
                }
                if(m2 >= query_bound){
                    isub<mod>(prv[ptr], mul<mod>(prv[lptr], mul_with));
                }
                else{
                    isub<mod>(prv[ptr], mul<mod>(add<mod>(t.get(1 + lptr), prv[lptr]), mul_with));
                }
                --ptr;
            }
            ll bound = query_bound/primes[k];
            if(bound * primes[k] == query_bound)
                --bound;
            for(ll i = 1; i <= bound; i++){
                if(i == 1 || lp[i] >= primes[k]){
                    ll j = i * primes[k];
                    size_t idx = lower_bound(state_elements.begin(), state_elements.end(), j) - state_elements.begin();
                    ll fun = modpow<mod>(j, coeff);
                    t.add(1 + idx, fun ? mod - fun : 0);
                }
            }
        }
        for(size_t i = 0; i < state_elements.size(); i++){
            if(state_elements[i] < query_bound){
                iadd<mod>(prv[i], t.get(1 + i));
            }
        }
        return prv;
    }
    State power3(State prv){
        ll q = primes[pi[cb] + 2];
        ll sum = 0;
        int ptr = 1;
        for(size_t i = 0; i < prv.size(); i++){
            while(ptr <= pi[cb] + 1 && primes[ptr] <= state_elements[i]){
                iadd<mod>(sum, prime_powers[ptr]);
                ++ptr;
            }
            iadd<mod>(prv[i], sum);
        }
        for(size_t i = 0; i < prv.size(); i++){
            ll m = state_elements[i];
            if(q * q <= m){
                for(int j = pi[cb] + 2; primes[j] * primes[j] <= m; j++){
                    ll p = primes[j];
                    isub<mod>(prv[i], mul<mod>(prime_powers[j], sub<mod>(prv[get_index(m/p)], prv[p - 2])));
                }
            }
        }
        return prv;
    }
    State power_calc(size_t coeff, PowerSum<mod> summator){
        State init(state_elements.size(), 0);
        for(size_t i = 0; i < state_elements.size(); i++){
            init[i] = summator.eval(state_elements[i]);
        }
        return power3(power2(power1(init), coeff));
    }
    State first_part(){
        State result(state_elements.size(), 0);
        prime_powers = vector<ll>(primes.size(), 1);
        for(size_t coeff = 0; coeff < polynomial.size(); coeff++){
            State curr = power_calc(coeff, PowerSum<mod>(coeff));
            for(size_t i = 0; i < state_elements.size(); i++){
                iadd<mod>(result[i], mul<mod>(curr[i], polynomial[coeff]));
                isub<mod>(result[i], polynomial[coeff]);
            }
            for(size_t i = 1; i < primes.size(); i++)
                imul<mod>(prime_powers[i], primes[i]);
        }
        prime_full = result;
        return result;
    }
    State step1(State prv){
        ll q = primes[pi[cb] + 1];
        State result(state_elements.size());
        for(size_t i = 0; i < result.size(); i++){
            ll m = state_elements[i];
            if(q * q <= m){
                result[i] = add<mod>(1, sub<mod>(prv[i], prv[q - 2]));
                for(int j = pi[cb] + 1; primes[j] * primes[j] <= m; j++)
                    iadd<mod>(result[i], add<mod>(f(primes[j], 2), mul<mod>(f(primes[j], 1), sub<mod>(prv[get_index(m/primes[j])], prv[primes[j] - 1]))));
            }
            else if(q <= m){
                result[i] = add<mod>(1, sub<mod>(prv[i], prv[q - 2]));
            }
            else{
                result[i] = 1;
            }
        }
        return result;
    }
    State step2(State prv){
        t.reset();
        for(int k = pi[cb]; k >= pi[root6] + 1; k--){
            size_t ptr = state_elements.size() - 1;
            while(state_elements[ptr] >= query_bound){
                ll m = state_elements[ptr];
                ll pw = primes[k];
                int pw_num = 1;
                while(pw <= m){
                    ll fun = f(primes[k], pw_num);
                    ll ask = m/pw;
                    size_t idx = get_index(ask);
                    if(ask >= query_bound){
                        iadd<mod>(prv[ptr], mul<mod>(fun, prv[idx]));
                    }
                    else{
                        iadd<mod>(prv[ptr], mul<mod>(fun, add<mod>(t.get(1 + idx), prv[idx])));
                    }
                    if(pw <= m/primes[k]){
                        ++pw_num;
                        pw *= primes[k];
                    }
                    else
                        break;
                }
                --ptr;
            }
            ll bound = query_bound/primes[k];
            if(bound * primes[k] == query_bound)
                --bound;
            for(ll i = 1; i <= bound; i++){
                if(i == 1 || lp[i] >= primes[k]){
                    ll j = i * primes[k];
                    size_t idx = lower_bound(state_elements.begin(), state_elements.end(), j) - state_elements.begin();
                    int pw_num = 0;
                    while(j%primes[k] == 0){
                        j /= primes[k];
                        ++pw_num;
                    }
                    t.add(1 + idx, mul<mod>(f(primes[k], pw_num), precalc_f[j]));
                }
            }
        }
        for(size_t i = 0; i < state_elements.size(); i++){
            if(state_elements[i] < query_bound){
                iadd<mod>(prv[i], t.get(1 + i));
            }
        }
        return prv;
    }
    State step3(State prv){
        State nxt(state_elements.size());
        for(int k = pi[root6]; k >= 1; k--){
            nxt.assign(state_elements.size(), 0);
            for(size_t i = 0; i < state_elements.size(); i++){
                ll m = state_elements[i];
                ll pw = 1;
                int pw_num = 0;
                ll bound = m/primes[k];
                while(pw <= m){
                    iadd<mod>(nxt[i], mul<mod>(pw_num ? f(primes[k], pw_num) : 1, prv[get_index(m/pw)]));
                    if(pw > bound)
                        break;
                    pw *= primes[k];
                    ++pw_num;
                }
            }
            nxt.swap(prv);
        }
        return prv;
    }
    State second_part(State prv){
        return all_full = step3(step2(step1(prv)));
    }
    ll solve_small(bool only_prime){
        if(n == 1){
            prime_full = {(ll)0};
            all_full = {(ll)1};
            return only_prime ? 0 : 1;
        }
        else{
            sieve(n);
            prime_full.resize(n);
            all_full.resize(n);
            prime_full[0] = 0;
            all_full[0] = 1;
            ll sum1 = 0, sum2 = 1;
            for(ll i = 2; i <= n; i++){
                if(lp[i] == i)
                    iadd<mod>(sum1, precalc_f[i]);
                iadd<mod>(sum2, precalc_f[i]);
                prime_full[i - 1] = sum1;
                all_full[i - 1] = sum2;
            }
            return only_prime ? sum1 : sum2;
        }
    }
    ll calculate(ll _n, bool only_prime = false){
        if(1 == mod)
            return 0;
        n = _n;
        if(n <= 128){
            return solve_small(only_prime);
        }
        sq = rounded_root(n, 2);
        cb = rounded_root(n, 3);
        root6 = rounded_root(n, 6);
        query_bound = n/cb;
        t = ModularFenwick<mod>(2 * sq + 3);
        sieve(2 * sq);
        for(ll i = 1; i <= sq; i++){
            state_elements.push_back(i);
            state_elements.push_back(n/i);
        }
        sort(state_elements.begin(), state_elements.end());
        state_elements.erase(unique(state_elements.begin(), state_elements.end()),
                state_elements.end());
        big.resize(sq + 1);
        size_t ptr = state_elements.size() - 1;
        for(ll i = 1; i <= sq; i++){
            ll val = n/i;
            while(state_elements[ptr] > val)
                --ptr;
            big[i] = ptr;
        }
        auto result = only_prime ? first_part() : second_part(first_part());
        return result.back();
    }
};

const ll mod = (ll)1e12;

ll func(ll p, ll k){
    return 1;
}

int main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    MultiplicativeSum<mod> solver(func, {1});
    solver.calculate(n, true);
    auto dp = solver.prime_full;
    auto lp = solver.lp;
    ll ans = 0;
    for(ll x = 2; x * x * x <= n; x++){
        if(lp[x] == x)++ans;
    }
    for(ll x = 2; x * x <= n; x++){
        if(lp[x] == x){
            ll all = dp[n > 128 ? solver.get_index(n/x) : (n/x - 1)];
            ll small = dp[x - 1];
            ans += all - small;
        }
    }
    cout << ans << endl;
    return 0;
}