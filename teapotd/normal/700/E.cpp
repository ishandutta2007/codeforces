#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr int INF = 1e9;

Vi buf, cnt;

// Stable countingsort; time: O(k+sz(vec))
// See example usage in radixSort for pairs.
template<class F>
void countSort(Vi& vec, F key, int k) {
    vec.swap(buf);
    vec.resize(sz(buf));
    cnt.assign(k+1, 0);
    each(e, buf) cnt[key(e)]++;
    rep(i, 1, k+1) cnt[i] += cnt[i-1];
    for (int i = sz(vec)-1; i >= 0; i--)
        vec[--cnt[key(buf[i])]] = buf[i];
}

// Compute order of elems, k is max key; O(n)
Vi radixSort(const vector<Pii>& elems, int k) {
    Vi order(sz(elems));
    iota(all(order), 0);
    countSort(order,
        [&](int i) { return elems[i].y; }, k);
    countSort(order,
        [&](int i) { return elems[i].x; }, k);
    return order;
}

// KS algorithm for suffix array; time: O(n)
// Input values are assumed to be in [1;k]
Vi sufArray(Vi str, int k) {
    int n = sz(str);
    Vi suf(n);
    str.resize(n+15);

    if (n < 15) {
        iota(all(suf), 0);
        rep(j, 0, n) countSort(suf,
            [&](int i) { return str[i+n-j-1]; }, k);
        return suf;
    }

    // Compute triples codes
    Vi tmp, code(n+2);
    rep(i, 0, n) if (i % 3) tmp.pb(i);

    rep(j, 0, 3) countSort(tmp,
        [&](int i) { return str[i-j+2]; }, k);

    int mc = 0, j = -1;

    each(i, tmp) {
        code[i] = mc += (j == -1 ||
                str[i] != str[j] ||
                str[i+1] != str[j+1] ||
                str[i+2] != str[j+2]);
        j = i;
    }

    // Compute suffix array of 2/3
    tmp.clear();
    for (int i=1; i < n; i += 3) tmp.pb(code[i]);
    tmp.pb(0);
    for (int i=2; i < n; i += 3) tmp.pb(code[i]);
    tmp = sufArray(move(tmp), mc);

    // Compute partial suffix arrays
    Vi third;
    int th = (n+4) / 3;
    if (n%3 == 1) third.pb(n-1);

    rep(i, 1, sz(tmp)) {
        int e = tmp[i];
        tmp[i-1] = (e < th ? e*3+1 : (e-th)*3+2);
        code[tmp[i-1]] = i;
        if (e < th) third.pb(e*3);
    }

    tmp.pop_back();
    countSort(third,
        [&](int i) { return str[i]; }, k);

    // Merge suffix arrays
    merge(all(third), all(tmp), suf.begin(),
        [&](int l, int r) {
            while (l%3 == 0 || r%3 == 0) {
                if (str[l] != str[r])
                    return str[l] < str[r];
                l++; r++;
            }
            return code[l] < code[r];
        });

    return suf;
}

// KS algorithm for suffix array; time: O(n)
Vi sufArray(const string& str) {
    return sufArray(Vi(all(str)), 255);
}

// Compute Longest Common Prefix array for
// given string and it's suffix array; O(n)
// In order to compute suffix array use kmr.h
// or suffix_array_linear.h
template<class T>
Vi lcpArray(const T& str, const Vi& sufs) {
    int n = sz(str), k = 0;
    Vi pos(n), lcp(n-1);
    rep(i, 0, n) pos[sufs[i]] = i;
    rep(i, 0, n) {
        if (pos[i] < n-1) {
            int j = sufs[pos[i]+1];
            while (i+k < n && j+k < n &&
                    str[i+k] == str[j+k]) k++;
            lcp[pos[i]] = k;
        }
        if (k > 0) k--;
    }
    return lcp;
}

// Range Minimum Query; space: O(n lg n)
struct RMQ {
    using T = int;
    static constexpr T ID = INF;
    T f(T a, T b)  { return min(a, b); }

    vector<vector<T>> s;

    // Initialize RMQ structure; time: O(n lg n)
    RMQ(const vector<T>& vec = {}) {
        s = {vec};
        for (int h = 1; h <= sz(vec); h *= 2) {
            s.emplace_back();
            auto& prev = s[sz(s)-2];
            rep(i, 0, sz(vec)-h*2+1)
                s.back().pb(f(prev[i], prev[i+h]));
        }
    }

    // Query f(s[b], ... ,s[e-1]); time: O(1)
    T query(int b, int e) {
        if (b >= e) return ID;
        int k = 31 - __builtin_clz(e-b);
        return f(s[k][b], s[k][e - (1<<k)]);
    }
};

// Segment tree (point, interval)
// Configure by modifying:
// - T - stored data type
// - ID - neutral element for query operation
// - merge(a, b) - combine results
struct SegmentTree {
    using T = int;
    static constexpr T ID = INF;
    static T merge(T a, T b) { return min(a,b); }

    vector<T> V;
    int len;

    SegmentTree(int n = 0, T def = ID) {
        for (len = 1; len < n; len *= 2);
        V.resize(len*2, ID);
        rep(i, 0, n) V[len+i] = def;
        for (int i = len-1; i > 0; i--)
            V[i] = merge(V[i*2], V[i*2+1]);
    }

    void set(int i, T val) {
        V[i+=len] = val;
        while ((i/=2) > 0)
            V[i] = merge(V[i*2], V[i*2+1]);
    }

    T query(int begin, int end) {
        begin += len; end += len-1;
        if (begin > end)  return ID;
        if (begin == end) return V[begin];
        T x = merge(V[begin], V[end]);

        while (begin/2 < end/2) {
            if (~begin&1) x = merge(x, V[begin^1]);
            if (end&1)    x = merge(x, V[end^1]);
            begin /= 2; end /= 2;
        }
        return x;
    }
};

constexpr SegmentTree::T SegmentTree::ID;

// ---

int n;
string s;
Vi sufs, sufId;
RMQ lcp;
SegmentTree avail;

template<class F>
int bsearch(int begin, int end, F pred) {
    while (begin+1 < end) {
        int mid = (begin+end) / 2;
        if (pred(mid)) {
            begin = mid;
        } else {
            end = mid;
        }
    }
    return begin;
}

int nextOcc(int begin, int end) {
    int id = sufId[begin];
    int fs = bsearch(-1, id, [&](int i) { return lcp.query(i, id) < end-begin; }) + 1;
    int ls = bsearch(id, n, [&](int i) { return lcp.query(id, i) >= end-begin; }) + 1;
    return min(avail.query(fs, id), avail.query(id+1, ls));
}

bool eq(int begin1, int begin2, int len) {
    int id1 = sufId[begin1], id2 = sufId[begin2];
    if (id1 == id2) return 1;
    if (id1 > id2) swap(id1, id2);
    return lcp.query(id1, id2) >= len;
}

int solve(int begin) {
    int ans = 1, end = begin+1;

    while (true) {
        int nxt = nextOcc(begin, end);
        if (nxt == INF) return ans;

        int step = nxt-begin;
        int times = bsearch(1, n/step+1, [&](int k) { return eq(begin, nxt, end-begin+step*k); });

        end += step*times;
        ans += times;
    }
}

void run() {
    cin >> n >> s;
    sufs = sufArray(s);
    sufId.resize(n+1);
    rep(i, 0, sz(sufs)) sufId[sufs[i]] = i;
    lcp = {lcpArray(s, sufs)};
    avail = {sz(sufs)};

    int ans = 0;

    for (int i = n-1; i >= 0; i--) {
        avail.set(sufId[i], i);
        ans = max(ans, solve(i));
    }

    cout << ans << '\n';
}