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

string repeat(string s, int n) {
    string t;
    while (n--) t += s;
    return t;
}

string kek(string s, int n) {
    return string(n, s[0]) + string(n, s[1]) + string(n, s[2]);
}

void run() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if (t == "aa" || t == "bb" || t == "cc") {
        swap(s, t);
    }

    map<char, char> to, from;

    auto put = [&](char c) {
        if (to.count(c)) return to[c];
        char chr = char(sz(to)+'a');
        to[c] = chr;
        from[chr] = c;
        return chr;
    };

    each(c, s) c = put(c);
    each(c, t) c = put(c);
    put('a'); put('b'); put('c');

    string ans;
    deb(s, t, to, from);

    if (s == "aa") {
        if (t == "aa") {
            ans = repeat("abc", n);
        } else if (t == "ab") {
            ans = repeat("cba", n);
        } else if (t == "ba") {
            ans = repeat("abc", n);
        } else if (t == "bc") {
            ans = repeat("cba", n);
        } else if (t == "bb") {
            ans = repeat("abc", n);
        } else {
            assert(1 == 2);
        }
    } else {
        if (t == "ab") {
            ans = kek("bac", n);
        } else if (t == "ba") {
            ans = kek("acb", n);
        } else if (t == "ac") {
            ans = kek("cba", n);
        } else if (t == "ca") {
            ans = kek("cba", n);
        } else if (t == "bc") {
            ans = kek("cba", n);
        } else if (t == "cb") {
            ans = kek("bca", n);
        } else {
            assert(3 == 4);
        }
    }

    if (ans.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        each(c, ans) cout << from[c];
        cout << '\n';
    }
}