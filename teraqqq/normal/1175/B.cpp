#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using res_t = uint32_t;

string op;
int l, n;
bool overflow = false;

res_t calc_for() {
    res_t res = 0;
    for(; l--; ) {
        res_t prev = res;
        cin >> op;
        if(op[0] == 'a') ++res;
        else if(op[0] == 'f') {
            res_t _t; cin >> _t;
            ll llres = res + (ll)_t*calc_for();
            if(llres >= (1LL<<32)) overflow = true;
            res = (res_t)llres;
        }
        else if(op[0] == 'e') break;
        if(prev > res) overflow = true;
    }
    return res;
}

int main() {
    cin >> l;
    res_t res = calc_for();
    if(overflow) cout << "OVERFLOW!!!" << endl;
    else cout << res << endl;
}