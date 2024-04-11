#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "? " << 1 << " " << n << endl;
    int pos;
    cin >> pos;
    int l = pos + 1, r = n, f = 0;
    int x;
    if(pos > 1) {
        cout << "? " << 1 << " " << pos << endl;
        cin >> x;
        if(x == pos) l = 1, r = pos - 1, f = 1;
    }
    while(l < r) {
        int m;
        if(f) m = (l + r + 1) / 2;
        else m = (l + r) / 2;
        if(f) {
            cout << "? " << m << " " << pos << endl;
        } else {
            cout << "? " << pos << " " << m << endl;
        }
        cin >> x;
        if(x == pos) {
            if(f) {
                l = m;
            } else {
                r = m;
            }
        } else {
            if(f) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    cout << "! " << l << endl;
}