#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "vanity";

typedef long long base;

///y = ax + b
struct line {
    base a, b;
    line() {}
    line(base a_, base b_) {
        a = a_;
        b = b_;
    }
    base f(base X) {
        return a * X + b;
    }
};

long double cross(line a, line b) {
    return (long double)(b.b - a.b) / (a.a - b.a);
}

struct envelope {
    bool reverse = false;
    vector <line> st;
    int Last = -1;
    envelope() {}
    void push_back(line a) {
        while (st.size() > 1) {
            if (st[Last].a == a.a) return;
            if ((cross(st[Last - 1], st[Last]) == cross(st[Last - 1], a))) {
                st.pop_back(); --Last; continue;
            }
            if ((cross(st[Last - 1], st[Last]) > cross(st[Last - 1], a)) ^ reverse) {
                st.pop_back(); --Last;
            } else {
                break;
            }
        }
        st.pb(a);
        ++Last;
    }
    int id(int i) {
        if (reverse)
            return (int)st.size() - i - 1;
        return i;
    }
    base f(base X) {
        int L = -1, R = Last;
        while (R - L > 1) {
            int M = (R + L) >> 1;
            if ((cross(st[id(M)], st[id(M + 1)]) > X)) {
                R = M;
            } else {
                L = M;
            }
        }
        return st[id(R)].f(X);
    }
};

vector <line> func[2];

int n;
base pref[200001];
envelope F[2];
vector <base> a;
///a[l] * (r - l) - pref[r]     + pref[l]     = (a[l] * r - pref[r]) + (pref[l] - a[l] * l)
///a[r] * (l - r) - pref[l - 1] + pref[r - 1] = (a[r] * l - pref[l - 1]) + (pref[r - 1] - a[r] * r)
base CNT, ans;

int main() {
    ios::sync_with_stdio(false);//cout << "KEK";
    //files(FileName);
    cin >> n;
    For(i, 0, n) {
        base b; cin >> b; a.pb(b);
        pref[i + 1] = pref[i] + b;
        CNT += b * (i + 1);
    }
    F[0].reverse = true;
    Out(i, n, 0) {
        F[0].pb(line(i, -pref[i + 1]));
        ans = max(ans, F[0].f(a[i]) + pref[i + 1] - a[i] * i);
    }
    For(i, 0, n) {
        F[1].pb(line(i, -pref[i]));
        ans = max(ans, F[1].f(a[i]) + pref[i] - a[i] * i);
    }
    cout << CNT + ans << endl;
}
/*
5
1 2 3 4 5
1 2 3 4 5
1 4 9 16 25
1 5 14 30 55
*/