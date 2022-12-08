//
// Created by yamunaku on 2020/12/25.
//

#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repl(i, l, r) for(ll i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)
#define int long long

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

/*
  The implementation of Miller-Rabin Test with C++
  varified with ALDS1_1_C

  http://joisino.hatenablog.com/entry/2017/08/03/210000

  Copyright (c) 2017 joisino
  Released under the MIT license
  http://opensource.org/licenses/mit-license.php
 */
struct Miller {
    const vector<long long> v = {2, 7, 61}; // < 4,759,123,141
    // x^k (mod m)
    long long modpow(long long x, long long k, long long m) {
        long long res = 1;
        while (k) {
            if (k & 1) {
                res = res * x % m;
            }
            k /= 2;
            x = x * x % m;
        }
        return res;
    }

    // check if n is prime
    bool check(long long n) {
        if (n < 2) {
            return false;
        }
        long long d = n - 1;
        long long s = 0;
        while (d % 2 == 0) {
            d /= 2;
            s++;
        }
        for (long long a : v) {
            if (a == n) {
                return true;
            }
            if (modpow(a, d, n) != 1) {
                bool ok = true;
                for (long long r = 0; r < s; r++) {
                    if (modpow(a, d * (1LL << r), n) == n - 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return false;
                }
            }
        }
        return true;
    }
};

Miller miller;

void cno() {
    cout << 0 << endl;
    exit(0);
}

signed main() {
    //CFS;
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    vl x(n);
    set<ll> st;
    rep(i, n) {
        cin >> x[i];
        st.insert(x[i]);
    }
    map<ll, vl> ps;
    rep(i, n) {
        if (x[i] < IINF) {
            if (miller.check(x[i])) ps[x[i]].push_back(x[i]);
        }
        ll p = round(sqrt(x[i]));
        if (p * p != x[i]) continue;
        if (miller.check(p)) ps[p].push_back(x[i]);
    }
    int hup = 1000001;
    vl hurui(hup, true);
    hurui[0] = hurui[1] = false;
    repl(i, 2, hup) {
        if (hurui[i]) {
            ll tmp = (ll) i * i;
            while (tmp <= (LINF + i - 1) / i) {
                tmp *= i;
                if (st.find(tmp) != st.end()) ps[i].push_back(tmp);
            }
            for (int j = i + i; j < hup; j += i) {
                hurui[j] = false;
            }
        }
    }
    vl kesu;
    int amari = 0;
    ll id3 = -1;
    for (auto &p : ps) {
        if (p.second.size() == 1) kesu.push_back(p.first);
        else {
            amari += (int) p.second.size() - 2;
            if (p.second.size() >= 3) id3 = p.first;
        }
    }
    for (auto &a : kesu) ps.erase(a);
    mti factor(n);
    vl use(n, true);
    vl comp;
    int c = 0;
    int miid = -1;
    rep(i, n) {
        ll tmp = x[i];
        for (auto &p : ps) {
            if (tmp % p.first == 0) {
                while (tmp % p.first == 0) {
                    tmp /= p.first;
                }
                factor[i].push_back(p.first);
            }
        }
        if (tmp != 1) use[i] = false;
        else {
            c++;
            if (factor[i].size() >= 2) {
                comp.push_back(i);
                if (miid == -1) miid = i;
                else if (factor[i].size() < factor[miid].size()) miid = i;
            }
        }
    }
    if (c < k) cno();
    if (c - k <= (int) comp.size()) {
        rep(i, c - k) {
            use[comp[i]] = false;
        }
        rep(i, n) if (use[i]) cout << x[i] << " ";
        cout << endl;
        return 0;
    }
    c -= comp.size();
    if (c - k <= amari) {
        amari = amari - (c - k);
        for (auto &p : ps) {
            auto &v = p.second;
            cout << v[0] SP v[1] << " ";
            repl(i, 2, v.size()) {
                if (amari > 0) {
                    cout << v[i] << " ";
                    amari--;
                } else {
                    break;
                }
            }
        }
        cout << endl;
        return 0;
    }
    if (k % 2) {
        if (amari >= 1) {
            cout << ps[id3][0] SP ps[id3][1] SP ps[id3][2] << " ";
            k -= 3;
            for (auto &p : ps) {
                if (p.first == id3) continue;
                if (k > 0) {
                    cout << p.second[0] SP p.second[1] << " ";
                    k -= 2;
                }
            }
            cout << endl;
            return 0;
        }
        if (miid == -1) cno();
        if (factor[miid].size() > k / 2) cno();
        cout << x[miid] << " ";
        k--;
        set<ll> up;
        for (auto &p : factor[miid]) {
            cout << ps[p][0] SP ps[p][1] << " ";
            up.insert(p);
            k -= 2;
        }
        for (auto &p : ps) {
            if (up.find(p.first) != up.end()) continue;
            if (k > 0) {
                cout << p.second[0] SP p.second[1] << " ";
                k -= 2;
            } else {
                break;
            }
        }
        cout << endl;
    } else {
        for (auto &p : ps) {
            if (k > 0) {
                cout << p.second[0] SP p.second[1] << " ";
                k -= 2;
            } else {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}