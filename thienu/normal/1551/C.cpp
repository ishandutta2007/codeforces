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

    Vec(vi _v){
        v = _v;
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

const int A = 5;

void solve(){
    int n;
    cin >> n;
    vector<Vec<A>> v;
    for(int i = 0; i < n; i++){
        string s;
        vi vv(5);
        cin >> s;
        for(char c : s){
            vv[c-'a']++;
        }
        Vec<A> vec(vv);
        v.push_back(vec);
    }
    debug(v);

    int ans = 0;
    for(int cand = 0; cand < A; cand++){
        vi delta;
        for(int i = 0; i < n; i++){
            delta.push_back(2 * v[i].v[cand] - v[i].sum());
        }
        int cur = 0;
        sort(delta.begin(), delta.end(), greater<int>());
        for(int i = 0; i < n; i++){
            cur += delta[i];
            if(cur > 0){
                ans = max(ans, i+1);
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}