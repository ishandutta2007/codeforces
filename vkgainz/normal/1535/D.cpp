#include <bits/stdc++.h>
using namespace std;
using ll = long long;


string s;
int w[400000];
int f[400000], ba[400000];

void build() {
    for(int i = (s.length() + 1) / 2; i < s.length() + 1; i++) {
        if(s[ba[i]] == '?') {
            w[i] = 2;
        }
        else w[i] = 1;
    }
    for(int i = (s.length() - 1) / 2; i >= 1; i--) {
        if(s[ba[i]] == '?') {
            w[i] = w[2 * i] + w[2 * i + 1];
        }
        else if(s[ba[i]] == '0') {
            w[i] = w[2 * i];
        }
        else {
            w[i] = w[2 * i + 1];
        }
    }
}

void upd(int p, char c) {
    s[p] = c;
    //upd initial
    p = f[p];
    if(p >= (s.length() + 1) / 2) {
        int idx = ba[p];
        if(s[idx] == '?') w[p] = 2;
        else w[p] = 1;
        p /= 2;
    }
    while(p >= 1) {
        //cout << p << " bayus" << "\n";
        int idx = ba[p];
        if(s[idx] == '?')
            w[p] = w[2 * p] + w[2 * p + 1];
        else if(s[idx] == '0')
            w[p] = w[2 * p];
        else 
            w[p] = w[2 * p + 1];
        p /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;
    cin >> s;
    int x = 0, y = (1 << (k - 1));
    for(int b = k - 1; b >= 0; b--) {
        for(int st = x; st < x + (1 << b); st++) {
            f[st] = y;
            ba[y] = st;
            ++y;
        }
        x += (1 << b);
        y -= (1 << b);
        if(b)
            y -= (1 << (b - 1));
    }
    build();
    int q; cin >> q;
    while(q--) {
        int p;
        char c; cin >> p >> c;
        --p;
        upd(p, c);
        cout << w[1] << "\n";
    }

}