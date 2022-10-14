#include <bits/stdc++.h>


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);

    set<array<int64_t, 2>> a;
    set<array<int64_t, 2>> b;

    int N;
    cin >> N;
    int64_t i = 0;
    for(int j=0; j < N; j++) {
        int q; cin >> q;
        if( q == 1 ) {
            int64_t x;
            cin >> x;
            a.insert({i + 1, -x});
            b.insert({-x, i+1});
            ++i;
        } else if( q== 2 ) {
            array<int64_t, 2> t = *a.begin();
            a.erase(t);
            array<int64_t, 2> v = {t[1], t[0]};
            b.erase(v);
            cout << t[0] << " ";
        } else {
            array<int64_t, 2> t = *b.begin();
            b.erase(t);
            array<int64_t, 2> v = {t[1], t[0]};
            a.erase(v);
            cout << t[1] << " ";
        }
    }
}