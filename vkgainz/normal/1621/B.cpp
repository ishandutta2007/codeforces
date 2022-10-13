#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mnL = 1e9, mxR = 0;
        int cL = 0, cR = 0;
        map<pair<int, int>, int> in;
        for (int i = 0; i < n; i++) {
            int l, r, c; cin >> l >> r >> c;
            if (in.find(make_pair(l, r)) == in.end()) {
                in[make_pair(l, r)] = c;
            } else {
                in[make_pair(l, r)] = min(in[make_pair(l, r)], c);
            }
            if (r > mxR) {
                mxR = r;
                cR = c;
            } else if (r == mxR) {
                cR = min(cR, c);
            }
            if (l < mnL) {
                mnL = l;
                cL = c;
            } else if (l == mnL) {
                cL = min(cL, c);
            }
            int ans = cL + cR;
            if (in.count({mnL, mxR})) {
                ans = min(ans, in[make_pair(mnL, mxR)]);
            }
            cout << ans << "\n";
        }
    }
}