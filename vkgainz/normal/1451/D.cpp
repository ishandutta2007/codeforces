#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e6+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int d; cin >> d;
        int k; cin >> k;
        bool w = 1;
        for(int i=1;k*1LL*k*i*1LL*i<=d*1LL*d;i++) {
            ll l = 2*1LL*i*1LL*i*1LL*k*1LL*k;
            ll r = k*1LL*k*1LL*(2*1LL*i*1LL*i+2*1LL*i+1);
            if(l<=d*1LL*d && r>d*1LL*d) {
                w = 0;
                break;
            }
        }
        if(w) cout << "Ashish" << endl;
        else cout << "Utkarsh" << endl;
    }
}