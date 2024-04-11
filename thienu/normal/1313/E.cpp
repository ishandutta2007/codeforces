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

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
vi Z(string S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

void st_set(vll &st, int tl, int tr, int pos, int idx, ll val){
    if(tl == tr){
        st[pos] = val;
        return;
    }
    if(idx <= tl + (tr - tl) / 2){
        st_set(st, tl, tl + (tr - tl) / 2, pos * 2, idx, val);
    }else{
        st_set(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, idx, val);
    }
    st[pos] = st[2 * pos] + st[2 * pos + 1];
}

void st_add(vll &st, int tl, int tr, int pos, int idx, ll val){
    if(tl == tr){
        st[pos] += val;
        return;
    }
    if(idx <= tl + (tr - tl) / 2){
        st_add(st, tl, tl + (tr - tl) / 2, pos * 2, idx, val);
    }else{
        st_add(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, idx, val);
    }
    st[pos] = st[2 * pos] + st[2 * pos + 1];
}


ll st_sum(vll &st, int tl, int tr, int pos, int left, int right){
    if(tr < left || right < tl){
        return 0;
    }
    if(left <= tl && tr <= right){
        return st[pos];
    }
    
    return st_sum(st, tl, tl + (tr - tl) / 2, pos * 2, left, right)
            + st_sum(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
}

void solve(){
    int n, m;
    string a, b, s;
    cin >> n >> m >> a >> b >> s;
    vi pref = Z(s + '&' + a);
    pref = vector<int>(pref.begin() + m+1, pref.end());
    debug(pref);
    reverse(s.begin(), s.end());
    reverse(b.begin(), b.end());
    vi suf = Z(s + '&' + b);
    suf = vector<int>(suf.begin() + m+1, suf.end());
    reverse(s.begin(), s.end());
    reverse(b.begin(), b.end());
    reverse(suf.begin(), suf.end());
    debug(suf);

    // vvi prefs(n+1), sufs(n+1);
    // for(int i = 0; i < n; i++){
    //     prefs[pref[i]].push_back(i);
    //     sufs[suf[i]].push_back(i);
    // }

    ll ans = 0;

    vll stl(4 * n+4), stc(4 * n+4);
    // build for i=0 -> j=0..min(m-2, n-1)
    for(int j = 0; j <= min(m-2, n-1); j++){
        st_add(stl, 0, n, 1, suf[j], suf[j]);
        st_add(stc, 0, n, 1, suf[j], 1);
    }
    for(int i = 0; i < n; i++){
        int limit = m - pref[i];
        debug(limit);
        ll valid = st_sum(stc, 0, n, 1, limit, n);
        debug(valid);
        ll linear = st_sum(stl, 0, n, 1, limit, n);
        debug(linear);
        debug(linear + valid * (pref[i] - m + 1));
        ans += linear + valid * ((ll) pref[i] - m + 1);
        
        // build for i=i+1 -> remove j=i, add j=m-2+i+1 if needed
        st_add(stl, 0, n, 1, suf[i], -suf[i]);
        st_add(stc, 0, n, 1, suf[i], -1);
        int nxt = m-2+i+1;
        debug(i, nxt);
        if(nxt < n){
            st_add(stl, 0, n, 1, suf[nxt], suf[nxt]);
            st_add(stc, 0, n, 1, suf[nxt], 1);
        }
    }

    for(int i = 0; i < n; i++){
        if(pref[i] == m){
            ans-=m-1;
        }
        if(suf[i] == m){
            ans-=m-1;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}