#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

struct Suffix_Array{
    vector<int> sa;
    const string s;
    const int n;

    Suffix_Array(const string &s) : s(s), n(s.size()){
        sa.resize(n);
        iota(begin(sa), end(sa), 0);
        sort(begin(sa), end(sa), [&](int a, int b){
            return s[a] == s[b] ? a > b : s[a] < s[b]; 
        });
        vector<int> rank(n), c(begin(s), end(s)), cnt(n);
        for(int len = 1; len < n; len <<= 1){
            for(int i = 0; i < n; i++){
                if(i == 0 || c[sa[i-1]] != c[sa[i]]) rank[sa[i]] = i;
                else{
                    if(sa[i-1]+len >= n || c[sa[i-1]+len/2] != c[sa[i]+len/2]) rank[sa[i]] = i;
                    else rank[sa[i]] = rank[sa[i-1]];
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(sa), end(sa), c.begin());
            for(int i = 0; i < n; i++){
                int j = c[i]-len;
                if(j >= 0) sa[cnt[rank[j]]++] = j;
            }
            swap(rank, c);
        }
    }

    int operator [] (int i) const {return sa[i];}

    int size() const {return n;}

    bool compare_substr(const string &t, int si = 0, int ti = 0) const{ //ssitti
        int m = t.size();
        while(si < n && ti < m){
            if(s[si] != t[ti]) return s[si] < t[ti];
            si++, ti++;
        }
        return si == n && ti < m;
    }

    int lower_bound(const string &t) const{ //t
        int l = -1, r = n;
        while(r-l > 1){
            int m = (l+r)/2;
            (compare_substr(t, sa[m]) ? l : r) = m;
        }
        return r;
    }

    int upper_bound(string t) const{
        t.back()++;
        return lower_bound(t);
    }
};

struct Longest_Common_Prefix_Array{
    vector<int> rank, lcp;
    const Suffix_Array sa;
    const int n;

    Longest_Common_Prefix_Array(const Suffix_Array &sa) : sa(sa), n(sa.size()){
        rank.resize(n), lcp.resize(n-1);
        for(int i = 0; i < n; i++) rank[sa[i]] = i;
        int h = 0;
        for(int i = 0; i < n; i++){
            if(rank[i]+1 < n){
                int j = sa[rank[i]+1];
                while(max(i, j)+h < n && sa.s[i+h] == sa.s[j+h]) h++;
                lcp[rank[i]] = h;
                if(h > 0) h--;
            }
        }
    }

    int operator [] (int i) const {return lcp[i];}
};

int main(){
    int N, K; cin >> N >> K;

    string S; cin >> S;
    S += S;

    Suffix_Array sa(S);
    
    int pos = N;

    bool flag = false;
    each(e, sa.sa){
        if(flag) chmin(pos, e);
        if(e == 0) flag = true;
    }

    S.resize(pos);
    string T;
    while(sz(T) < K) T += S;
    T.resize(K);
    cout << T << '\n';
}