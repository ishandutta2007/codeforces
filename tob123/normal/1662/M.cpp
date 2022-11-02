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
        int n, m;
        cin >> n >> m;
        int r = 0, w = 0;
        for(int i = 0; i < m; ++i) {
            int rt, wt;
            cin >> rt >> wt;
            r = max(r, rt);
            w = max(w, wt);
        }
        if(r + w > n) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            for(int i = 0; i < r; ++i) {
                cout << "R";
            }
            for(int i = 0; i < w; ++i) {
                cout << "W";
            }
            for(int i = r + w; i < n; ++i) {
                cout << "R";
            }
            cout << endl;
        }
    }

}