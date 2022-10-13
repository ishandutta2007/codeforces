#include <bits/stdc++.h>
using namespace std;

struct store {
    long long num;
    string pref;
    string suf;
};


store comb(store &x, store &y) {
    store ret = {0, "", ""};
    ret.num = x.num + y.num;
    if(x.pref.length() < 4) {
        string r = x.pref + y.pref;
        if(r.length() < 4) ret.pref = r;
        else ret.pref = r.substr(0, 4);
    }
    else ret.pref = x.pref;
    if(y.suf.length() < 4) {
        string r = x.suf + y.suf;
        if(r.length() < 4) ret.suf = r;
        else ret.suf = r.substr(r.length() - 4, 4);
    }
    else ret.suf = y.suf;

    for(int i = 1; i < 4; i++) {
        //i char from x, 4 - i from y
        if(i > x.suf.length() || 4 - i > y.pref.length()) continue;
        string cmp = x.suf.substr(x.suf.length() - i, i) + y.pref.substr(0, 4 - i);
        if(cmp == "haha") ++ret.num;
    }
    return ret;
}

store get_new(string x) {
    store ret = {0, "", ""};
    for(int i = 0; i < (int) x.length(); i++) {
        if(x.substr(i, 4) == "haha") ++ret.num;
    }
    if(x.length() < 4) {
        ret.pref = x, ret.suf = x;
    }
    else {
        ret.pref = x.substr(0, 4);
        ret.suf = x.substr(x.length() - 4, 4);
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<string, store> id;
        long long ans = 0LL;
        for(int i = 0; i < n; i++) {
            string x; cin >> x;
            string type; cin >> type;
            if(type[0] == ':') {
                string s; cin >> s;
                id[x] = get_new(s);
                ans = id[x].num;
            }
            else {
                string a; cin >> a;
                string plus; cin >> plus;
                string b; cin >> b;
                id[x] = comb(id[a], id[b]);
                ans = id[x].num;
            }
        }
        cout << ans << "\n";
    }
}