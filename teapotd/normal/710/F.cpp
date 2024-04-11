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

constexpr char AMIN = 'a';
constexpr int ALPHA = 26;

struct Aho {
    vector<array<int, ALPHA>> nxt{1};
    Vi suf = {-1}, acc = {0};

    int add(const string& str) {
        int i = 0;
        each(c, str) {
            if (!nxt[i][c-AMIN]) {
                nxt[i][c-AMIN] = sz(nxt);
                nxt.pb({}); suf.pb(-1);
                acc.pb(0);
            }
            i = nxt[i][c-AMIN];
        }
        acc[i]++;
        return i;
    }

    void build() {
        queue<int> que;
        each(e, nxt[0]) if (e) {
            suf[e] = 0; que.push(e);
        }
        while (!que.empty()) {
            int i = que.front(), s = suf[i], j = 0;
            que.pop();
            each(e, nxt[i]) {
                if (e) que.push(e);
                (e ? suf[e] : e) = nxt[s][j++];
            }
            acc[i] += acc[s];
        }
    }

    int next(int i, char c) {
        return nxt[i][c-AMIN];
    }

    int query(const string& s) {
        int ret = 0, cur = 0;
        each(c, s) {
            cur = next(cur, c);
            ret += acc[cur];
        }
        return ret;
    }
};

struct OnlineAho {
    vector<vector<string>> raw;
    vector<Aho> ds;

    void insert(const string& s) {
        raw.pb({s});

        while (sz(raw) >= 2) {
            auto& vec1 = raw[sz(raw)-2];
            auto& vec2 = raw[sz(raw)-1];
            if (sz(vec1) != sz(vec2)) break;
            vec1.insert(vec1.end(), all(vec2));
            raw.pop_back();
        }

        ds.resize(sz(raw));
        ds.back() = {};
        each(w, raw.back()) ds.back().add(w);
        ds.back().build();
    }

    int query(const string& s) {
        int ret = 0;
        each(a, ds) ret += a.query(s);
        return ret;
    }
};

void run() {
    int m; cin >> m;
    OnlineAho add, del;

    while (m--) {
        int t;
        string s;
        cin >> t >> s;

        if (t == 1) {
            add.insert(s);
        } else if (t == 2) {
            del.insert(s);
        } else {
            int ans = add.query(s) - del.query(s);
            cout << ans << endl;
        }
    }
}