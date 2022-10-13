#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int iter;

int query(int x0) {
    cout << "? " << x0 + 1 << "\n";
    cout.flush();
    int ans; cin >> ans;
    --ans;
    ++iter;
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<bool> vis(n);
        vector<int> p(n, -1);
        iter = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int st = query(i);
            int lst = st;
            vis[st] = true;
            vector<int> get;
            get.push_back(st);
            while (true) {
                int nxt = query(i);
                p[lst] = nxt;
                lst = nxt;
                vis[nxt] = true;
                // iter = 1 ==> get ans[0]
                // iter = 2 ==> get ans[ ans[0] ]
                // iter = 3 ==> get ans [ ans [ ans[0] ] ] 
                if (nxt == st) {
                    //end
                    break;
                }
                get.push_back(nxt);
            }

        }
        cout << "! ";
        for (int i = 0; i < n; i++) {
            cout << p[i] + 1 << " ";
        }
        cout << "\n";
        cout.flush();
    }
}