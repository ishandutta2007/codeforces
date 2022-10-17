#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <ll> a[2]; /// 0 - black, 1 - white

ll iptonum(string s) {
    //cerr << "iptonum " << s << "\n";
    ll res = 0;
    ll cres = 0;
    for (char c : s) {
        if (c == '.') {
            res = res * 256 + cres;
            cres = 0;
        }
        else {
            cres = cres * 10 + c - '0';
        }
    }
    res = res * 256 + cres;
    return res;
}

unordered_map <ll, int> M;
vector <ll> res;

ll getres(ll x) {
    //cerr << x << " " << M[x] << "\n";
    //cerr << x << " " << M[x] << "\n";
    if (M[x] == 1) {
        res.push_back(x);
        return 1;
    }
    else if (M[x] == 3) {
        ll t = getres(2 * x) + getres(2 * x + 1);
        return t;
    }
    else {
        return 0;
    }
}

void printotr(ll x) {
    for (int i = 32; ; i--) {
        if (x >= (1LL << i)) {
            x -=  (1LL << i);
            x <<= 32 - i;
            ll t[4];
            for (int j = 0; j < 4; j++) {
                t[j] = (x % 256);
                x /= 256;
            }
            for (int j = 3; j >= 0; j--) {
                cout << t[j];
                if (j)
                    cout << ".";
            }
            cout << "/" << i << "\n";
            break;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int korz = (s[0] == '+');
        s = s.substr(1);
        int t = s.find('/');
        if (t == -1) {
            a[korz].push_back((1LL << 32) + iptonum(s));
        }
        else {
            ll t1 = iptonum(s.substr(t + 1));
            ll t2 = iptonum(s.substr(0, t));
            a[korz].push_back((1LL << t1) + (t2 >> (32 - t1)));
        }
    }
    for (ll x : a[0]) {
        //cerr << x << "\n";
        for (ll t = x; t; t /= 2) {
            //cerr << ">> " << t << "\n";
            M[t] |= 1;
        }
    }
    for (ll x : a[1]) {
        //cerr << x << "\n";
        for (ll t = x; t; t /= 2) {
            //cerr << ">> " << t << "\n";
            M[t] |= 2;
        }
    }
    for (ll x : a[0]) {
        if (M[x] == 3) {
            cout << -1;
            return 0;
        }
    }
    for (ll x : a[1]) {
        if (M[x] == 3) {
            cout << -1;
            return 0;
        }
    }
    cout << getres(1) << "\n";
    for (ll x : res) {
        //cerr << x << "\n";
        printotr(x);
    }
    return 0;
}