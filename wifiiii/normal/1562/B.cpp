#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int isp(int x) {
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        string s;
        cin >> k >> s;
        for(char c : s) {
            if(!isp(c - '0')) {
                cout << 1 << endl;
                cout << c << endl;
                goto ok;
            }
        }
        for(int i = 0; i < k; ++i) {
            for(int j = i + 1; j < k; ++j) {
                int x = (s[i] - '0') * 10 + (s[j] - '0');
                if(!isp(x)) {
                    cout << 2 << endl;
                    cout << x << endl;
                    goto ok;
                }
            }
        }
        for(int i = 0; i < k; ++i) {
            for(int j = i + 1; j < k; ++j) {
                for(int r = 0; r < j + 1; ++r) {
                    int x = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                    if(!isp(x)) {
                        cout << 3 << endl;
                        cout << x << endl;
                        goto ok;
                    }
                }
            }
        }
        assert(0);
        ok:;
    }
}