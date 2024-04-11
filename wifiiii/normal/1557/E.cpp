#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int t;
    cin >> t;
    while(t--) {
        int win = 0;
        for(int i = 1; i <= 8; ++i) {
            int f = 0;
            for(int j = 1; j <= 8; ++j) {
                cout << i << " " << j << endl;
                string s;
                cin >> s;
                if(s == "Done") {
                    win = 1;
                    break;
                }
                if(f) {
                    if(s[0] == 'D') {
                        cout << i + 1 << " " << j << endl;
                        cin >> s;
                        if(s == "Done") {
                            win = 1;
                            break;
                        }
                        if(j == 1) {
                            cout << i + 1 << " " << 8 << endl;
                            cin >> s;
                            if(s == "Done") {
                                win = 1;
                                break;
                            }
                        }
                        break;
                    } else if(s[0] == 'U') {
                        if(j > 1) j = 0;
                    } else {
                        if(j > 1) ++j;
                    }
                }
                if(j >= 8) {
                    cout << i + 1 << " " << j - 1 << endl;
                    cin >> s;
                    if(s == "Done") {
                        win = 1;
                        break;
                    }
                }
                f = 1;
            }
            if(win) break;
        }
    }
}