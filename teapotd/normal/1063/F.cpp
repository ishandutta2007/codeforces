#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

struct KMR {
    vector<Vi> ids;

    KMR() {}
    explicit KMR(const string& str){ init(str); }

    void init(const string& str) {
        ids.clear();
        ids.push_back(Vi(all(str)));

        for (int h = 1; h <= sz(str); h *= 2) {
            vector<pair<Pii, int>> pairs;

            rep(j, 0, sz(str)) {
                int a = ids.back()[j], b = -1; 
                if (j+h < sz(str)) b = ids.back()[j+h];
                pairs.pb({ {a, b}, j });
            }

            sort(all(pairs));
            ids.emplace_back(sz(pairs));

            int n = 1;
            rep(j, 0, sz(pairs)) {
                if (j>0 && pairs[j-1].x != pairs[j].x)
                    n++;
                ids.back()[pairs[j].y] = n;
            }
        }
    }
};

Vi sufArray(const KMR& kmr) {
    Vi sufs(sz(kmr.ids.back()));
    iota(all(sufs), 0);
    sort(all(sufs), [&](int l, int r) {
        return kmr.ids.back()[l]<kmr.ids.back()[r];
    });
    return sufs;
}

template<class T>
Vi lcpArray(const T& str, const Vi& sufs, Vi& pos) {
    int n = sz(str), k = 0;
    Vi lcp(n-1);

    pos.resize(n);
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

// ---

struct SegmentTree {
    using T = int;
    static constexpr T ID = INT_MIN;
    static T merge(T a, T b) { return max(a,b); }

    vector<T> V;
    int len;

    SegmentTree(int n=0, T def=ID){init(n,def);}

    void init(int n, T def) {
        for (len = 1; len < n; len *= 2);
        V.assign(len+n, def);
        V.resize(len*2, ID);
        for (int i = len-1; i > 0; i--) update(i);
    }

    void update(int i) {
        V[i] = merge(V[i*2], V[i*2+1]);
    }

    void set(int i, T val) {
        V[i+=len] = val;
        while ((i/=2) > 0) update(i);
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

struct RMQ {
    using T = int;
    static constexpr T ID = INT_MAX;
    T f(T a, T b)  { return min(a, b); }

    vector<vector<T>> s;

    RMQ() {}
    RMQ(const vector<T>& vec) { init(vec); }

    void init(const vector<T>& vec) {
        s = {vec};
        for (int h = 1; h <= sz(vec); h *= 2) {
            s.emplace_back();
            auto& prev = s[sz(s)-2];
            rep(i, 0, sz(vec)-h*2+1)
                s.back().pb(f(prev[i], prev[i+h]));
        }
    }

    T query(int b, int e) {
        if (b >= e) return ID;
        int k = 31 - __builtin_clz(e-b);
        return f(s[k][b], s[k][e - (1<<k)]);
    }
};

// ---

template<class T>
int binSearch(int b, int e, T pred) {
    while (b+1 < e) {
        int m = (b+e) / 2;
        if (pred(m)) b = m;
        else e = m;
    }
    return b;
}

void run() {
    int n;
    string str;
    cin >> n >> str;

    Vi sufsPos, sufs = sufArray(KMR(str));
    RMQ lcp(lcpArray(str, sufs, sufsPos));

    Vi dp(n+1);
    SegmentTree avail(n+1);
    int k = 1, ans = 1;

    auto isAvailable = [&](int i, int len) {
        i = sufsPos[i];
        int from = binSearch(0, i+1, [&](int m) { return lcp.query(m-1, i) < len; });
        int to = binSearch(i, n, [&](int m) { return lcp.query(i, m) >= len; });
        return avail.query(from, to+1) >= len;
    };

    for (int i = n-1; i >= 0; i--) {
        while (k > 1 && !isAvailable(i, k-1) && !isAvailable(i+1, k-1)) {
            k--;
            avail.set(sufsPos[i+k], dp[i+k]);
        }

        dp[i] = k++;
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}