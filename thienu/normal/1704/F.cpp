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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int mex(set<int> s){
    int x = 0;
    while(s.find(x) != s.end()){
        x++;
    }
    return x;
}

const int N = 500;

vi dnim(N);

void dawson(){
    for(int i = 2; i < N; i++){
        set<int> s;
        for(int c = 0; c + 2 <= i; c++){
            s.insert(dnim[c] ^ dnim[i-c-2]);
        }
        dnim[i] = mex(s);
        // debug(i, v[i]);
    }
}

const int DPERIOD = 34;

int get_dawson(int len){
    if(len < N) return dnim[len];
    return dnim[len % DPERIOD + 10 * DPERIOD];
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int value = 0; // Alice = Left (bLue), Bob = Right (Red)
    int star = 0;
    // find the value of the game (= value + *star)
    vi alter(n);
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[i+1]) alter[i] = 1;
    }
    debug(alter);
    int i = 0;
    while(i < n){
        if(!alter[i]){
            value += (s[i] == 'B' ? 1 : -1);
            i++;
        }else{
            int run_length = 1;
            char c = s[i];
            i++;
            while(i < n && (alter[i-1])){
                i++;
                run_length++;
            }
            debug(run_length, c);
            if(run_length % 2 == 0){
                star ^= get_dawson(run_length);
            }else{
                star ^= get_dawson(run_length);
                value += (c == 'B' ? 1 : -1);
            }
        }
    }
    debug(value, star);
    if(value > 0){
        cout << "Bob" << endl;
    }else if(value < 0){
        cout << "Alice" << endl;
    }else if(star > 0){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dawson();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}