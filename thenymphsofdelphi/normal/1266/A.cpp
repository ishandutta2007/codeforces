#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 2e5 + 5;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while (q--){
        string s; cin >> s;
        int t = 0, cnt = 0;
        bool ck = 0;
        for (auto v: s){
            if (v == '0'){
                ck = 1;
            }
            if ((v - '0') % 2 == 0){
                cnt++;
            }
            t += v - '0';
        }
        if (t % 3 == 0 && ck && cnt >= 2) cout << "red" << endl;
        else cout << "cyan" << endl;
    }
}