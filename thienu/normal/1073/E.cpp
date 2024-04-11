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

ll MOD = 998244353;
ll ONE_NINTH = 443664157;

vvll powers;

int k;

void preprocess(){
    powers.resize(20);
    fill(powers.begin(), powers.end(), vll(20, 1));
    for(int i = 1; i < 20; i++){
        for(int j = 1; j < 20; j++){
            powers[i][j] = powers[i][j-1] * i % MOD;
        }
    }
}

ll process_segment(string pref, int num_extra_digits){
    debug(pref, num_extra_digits);
    // strip zeros
    int leading_zeros = 0;
    for(char c : pref){
        if(c == '0') leading_zeros++;
        else break;
    }
    pref = pref.substr(leading_zeros);
    debug(pref);

    ll ans = 0;

    set<char> digits;
    int pref_digit_sum = 0;
    for(char c : pref){
        digits.insert(c);
    }
    int num_digits = digits.size();
    for(char c : digits){
        pref_digit_sum += (c - '0');
    }

    if(num_extra_digits == 0){
        if(num_digits <= k){
            return stoll(pref) % MOD;
        }
        else{
            return 0;
        }
    }

    ll sum = 0;
    ll num = 0;
    // digits in suf but not in pref
    for(int mask = 0; mask < 1<<10; mask++){
        // check mask valid
        int total_bits = __builtin_popcount(mask) + num_digits;
        if(total_bits > k){
            continue;
        }
        bool ok = true;
        for(char c : pref){
            if((mask >> (c - '0')) & 1){
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        // inc-exc
        ll mask_sum = 0;
        ll mask_num = 0;
        for(int s = mask;; s = (s - 1) & mask){
            int digit_sum = pref_digit_sum;
            for(int i = 0; i < 10; i++){
                if((s >> i) & 1){
                    digit_sum += i;
                }
            }
            ll sub_num = powers[__builtin_popcount(s) + num_digits][num_extra_digits];
            ll sub_sum = (((powers[10][num_extra_digits] - 1) * ONE_NINTH) % MOD) * digit_sum % MOD;
            sub_sum = sub_sum * powers[__builtin_popcount(s) + num_digits][num_extra_digits - 1] % MOD;
            int multiplier = (__builtin_popcount(s) & 1) == (__builtin_popcount(mask) & 1) ? 1 : -1;
            mask_sum = ((mask_sum + sub_sum * multiplier) % MOD + MOD) % MOD;
            mask_num = ((mask_num + sub_num * multiplier) % MOD + MOD) % MOD;
            debug(mask, s, mask_sum, mask_num, digit_sum);
            if(s == 0) break;
        }

        sum = (sum + mask_sum) % MOD;
        num = (num + mask_num) % MOD;
        debug(mask, sum, num);
    }

    debug(sum, num);

    ll pref_ans = ((stoll(pref) % MOD) * powers[10][num_extra_digits] % MOD) * num % MOD;

    return (sum + pref_ans) % MOD;
}

ll split_segments(string l_str, string r_str){
    debug(l_str, r_str);
    if(l_str == r_str){
        return process_segment(l_str, 0);
    }
    int d = 0;
    while(d == l_str.size() || l_str[d] == r_str[d]) d++;
    string pref = l_str.substr(0, d);
    string l_suf = l_str.substr(d);
    string r_suf = r_str.substr(d);
    debug(d, pref, l_suf, r_suf);
    bool ok = true;
    for(char c : l_suf){
        if(c != '0') ok = false;
    }
    for(char c : r_suf){
        if(c != '9') ok = false;
    }
    if(ok){
        return process_segment(pref, l_suf.size());
    }
    string zeros;
    string nines;
    for(int i = 0; i < l_suf.size() - 1; i++){
        zeros += '0';
        nines += '9';
    }
    ll ans = 0;
    ans = (ans + split_segments(l_str, pref + l_suf[0] + nines) % MOD) % MOD;
    for(char c = l_suf[0] + 1; c < r_suf[0]; c++){
        ans = (ans + split_segments(pref + c + zeros, pref + c + nines) % MOD) % MOD;
    }
    ans = (ans + split_segments(pref + r_suf[0] + zeros, r_str) % MOD) % MOD;
    return ans;
}

void solve(){
    preprocess();

    ll l, r;
    cin >> l >> r >> k;

    // split into segments
    string l_str, r_str;
    l_str = to_string(l);
    r_str = to_string(r);
    int padding = r_str.size() - l_str.size();
    string pad_str = "";
    for(int i = 0; i < padding; i++){
        pad_str += '0';
    }
    l_str = pad_str + l_str;

    int n = l_str.size();

    debug(l_str, r_str);

    cout << split_segments(l_str, r_str) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}