#include <bits/stdc++.h>
using namespace std;

vector<int> seg;
int n;

void upd(int i) {
    seg[i += n]++;
    while(i > 1) {
        i /= 2;
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
}

int query(int l, int r) {
    int ans = 0;
    l += n, r += n;
    while(l < r) {
        if(l % 2) ans += seg[l++];
        if(r % 2) ans += seg[--r];
        l /= 2, r /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    seg.resize(2 * n);
    vector<int> p(n);
    long long inv = 0LL;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
        inv += query(p[i], n);
        upd(p[i]);
    }

    if(inv % 2 == 0) {
        if(3 * n % 2 == 0) cout << "Petr" << "\n";
        else cout << "Um_nik" << "\n";
    }
    else {
        if(3 * n % 2 == 0) cout << "Um_nik" << "\n";
        else cout << "Petr" << "\n";
    }
}