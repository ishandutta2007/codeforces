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

constexpr char AMIN = 'A'; // Smallest letter
constexpr int ALPHA = 4; // Set alphabet size

struct SufDFA {
    Vi len{0}, link{-1};
    vector<array<int, ALPHA>> to{ {} };
    int last{0}; // Current node (whole word)

    SufDFA() {}

    // Build suffix automaton for given string
    // and compute extended stuff; time: O(n)
    SufDFA(const string& s) {
        each(c, s) add(c);
    }

    // Append letter to the back
    void add(char c) {
        int v = last, x = c-AMIN;
        last = sz(len);
        len.pb(len[v]+1);
        link.pb(0);
        to.pb({});

        while (v != -1 && !to[v][x]) {
            to[v][x] = last;
            v = link[v];
        }

        if (v != -1) {
            int q = to[v][x];
            if (len[v]+1 == len[q]) {
                link[last] = q;
            } else {
                len.pb(len[v]+1);
                link.pb(link[q]);
                to.pb(to[q]);
                link[last] = link[q] = sz(len)-1;
                while (v != -1 && to[v][x] == q) {
                    to[v][x] = link[q];
                    v = link[v];
                }
            }
        }
    }

    // Go using edge `c` from state `i`.
    // Returns 0 if edge doesn't exist.
    int next(int i, char c) {
        return to[i][c-AMIN];
    }

    int shortest(char cFirst, char cLast) {
        int v = next(0, cFirst);
        if (!v) return 0;

        Vi dist(sz(len), -1);
        queue<int> que;
        que.push(v);
        dist[v] = 1;

        while (!que.empty()) {
            v = que.front();
            que.pop();

            if (!next(v, cLast)) {
                return dist[v];
            }

            each(e, to[v]) if (e && dist[e] == -1) {
                dist[e] = dist[v]+1;
                que.push(e);
            }
        }

        assert(0);
    }
};

using Matrix = array<array<ll, ALPHA>, ALPHA>;

constexpr ll INF = ll(1e18)+5;

Matrix mul(Matrix a, Matrix b) {
    Matrix c;
    rep(i, 0, ALPHA) rep(j, 0, ALPHA) {
        c[i][j] = INF;
        rep(k, 0, ALPHA) c[i][j] = min(c[i][j], a[i][k]+b[k][j]);
    }
    return c;
}

Matrix pow(Matrix a, ll e) {
    Matrix t = a;
    e--;
    while (e) {
        if (e % 2) t = mul(t, a);
        e /= 2; a = mul(a, a);
    }
    return t;
}

ll minLength(Matrix G, ll p) {
    Matrix H = pow(G, p);
    ll ret = INF;
    each(row, H) each(k, row) ret = min(ret, k);
    return ret;
}

void run() {
    ll n; cin >> n;
    string s; cin >> s;
    SufDFA dfa(s);

    Matrix G;

    rep(i, 0, ALPHA) {
        rep(j, 0, ALPHA) {
            G[i][j] = dfa.shortest(char(i+'A'), char(j+'A'));
            assert(G[i][j] > 0);
        }
    }

    ll begin = 0, end = n+1;

    while (begin+1 < end) {
        ll mid = (begin+end) / 2;
        if (minLength(G, mid) < n) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    cout << end << endl;
}