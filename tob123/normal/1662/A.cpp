#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define LL long long
#define st first
#define nd second
#define endl '\n'
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p[11];
        memset(p, -1, sizeof(p));
        for(int i = 0; i < n; ++i) {
            int b, d;
            cin >> b >> d;
            p[d] = max(p[d], b);
        }
        int ans = 0, pos = 1;
        for(int i = 1; i <= 10; ++i) {
            if(p[i] == -1) {
                pos = 0;
            }
            else {
                ans += p[i];
            }
        }
        if(pos) {
            cout << ans << endl;
        }
        else {
            cout << "MOREPROBLEMS" << endl;
        }
    }

}