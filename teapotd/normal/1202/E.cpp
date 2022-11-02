#define _USE_MATH_DEFINES
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

constexpr char AMIN = 'a'; // Smallest letter
constexpr int ALPHA = 26;  // Alphabet size

struct Aho {
    struct Node {
        int nxt[ALPHA], suf{-1}, nAcc{0};
    };

    vector<Node> V;
    Aho() { init(); }
    void init() { V.assign(1, {}); }

    void add(const string& str) {
        int i = 0;
        each(c, str) {
            if (!V[i].nxt[c-AMIN]) {
                V[i].nxt[c-AMIN] = sz(V);
                V.emplace_back();
            }
            i = V[i].nxt[c-AMIN];
        }
        V[i].nAcc++;
    }

    void build() {
        queue<int> que;
        each(e, V[0].nxt) if (e) {
            V[e].suf = 0;
            que.push(e);
        }
        while (!que.empty()) {
            int i = que.front(), s = V[i].suf, j = 0;
            que.pop();
            each(e, V[i].nxt) {
                if (e) que.push(e);
                (e ? V[e].suf : e) = V[s].nxt[j++];
            }
            V[i].nAcc += V[s].nAcc;
        }
    }

    int nxt(int i, char c) {
        return V[i].nxt[c-AMIN];
    }

    Vi matches(const string& s) {
        Vi ret = {0};
        int cur = 0;
        each(c, s) {
            cur = nxt(cur, c);
            ret.pb(V[cur].nAcc);
        }
        return ret;
    }
};

void run() {
    Aho aho, ahoRev;
    string t; cin >> t;
    int n; cin >> n;

    rep(i, 0, n) {
        string s; cin >> s;
        aho.add(s);
        reverse(all(s));
        ahoRev.add(s);
    }

    aho.build();
    ahoRev.build();

    Vi prefs = aho.matches(t);
    reverse(all(t));
    Vi sufs = ahoRev.matches(t);
    reverse(all(sufs));

    deb(prefs, sufs);
    ll ret = 0;

    rep(i, 0, sz(t)) {
        ret += ll(prefs[i]) * sufs[i];
        deb(i, prefs[i], sufs[i]);
    }

    cout << ret << endl;
}