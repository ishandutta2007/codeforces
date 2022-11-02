#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

long long ans, l, r, k;
vector<long long> v, vv;
int f[65][2][2][2][2][2][2];
long long fx[65][2][2][2][2][2][2], fy[65][2][2][2][2][2][2];

void rec(long long l, long long r, long long k, long long c) {
    if (k < 0) {
        return;
    }
    if ((c < ans) && (v.size() != 0)) {
        vv = v;
        ans = c;
    }
    if (l > r) {
        return;
    }
    rec(l + 1, r, k, c);
    v.push_back(l);
    rec(l + 1, r, k - 1, c ^ l);
    v.pop_back();
}

void brute() {
    ans = r + 10;
    v.clear();
    rec(l, r, k, 0);
    cout << ans << endl;
    cout << vv.size() << endl;
    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i] << " ";
    }
    cout << endl;
    exit(0);
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> l >> r >> k;
    if (k == 1) {
        cout << l << endl;
        cout << 1 << endl;
        cout << l << endl;
        return 0;
    }
    if (k == 2) {
        r = min(r, l + 4);
        brute();
    }
    if (k == 3) {
        if (l + 4 > r) {
            brute();
        }
        memset(f, 0, sizeof(f));
        f[0][0][0][0][0][0][0] = 1;
        vector<int> ll, rr;
        long long lt = l;
        for (int i = 0; i < 64; i++) {
            ll.push_back(l % 2);
            l /= 2;
            rr.push_back(r % 2);
            r /= 2;
        }
        reverse(ll.begin(), ll.end());
        reverse(rr.begin(), rr.end());
        for (int i = 0; i <= 64; i++) {
            for (int l0 = 0; l0 < 2; l0++) {
                for (int l1 = 0; l1 < 2; l1++) {
                    for (int l2 = 0; l2 < 2; l2++) {
                        for (int r0 = 0; r0 < 2; r0++) {
                            for (int r1 = 0; r1 < 2; r1++) {
                                for (int r2 = 0; r2 < 2; r2++) {
                                    if (f[i][l0][l1][l2][r0][r1][r2]) {
                                        if (i == 64) {
                                            puts("0");
                                            puts("3");
                                            cout << fx[i][l0][l1][l2][r0][r1][r2] << " ";
                                            cout << fy[i][l0][l1][l2][r0][r1][r2] << " ";
                                            cout << (fx[i][l0][l1][l2][r0][r1][r2] ^ fy[i][l0][l1][l2][r0][r1][r2]) << endl;
                                            // cout << fx[i][l0][l1][l2][r0][r1][r2] << " " << fy[i][l0][l1][l2][r0][r1][r2] << " " << fx[i][l0][l1][l2][r0][r1][r2] ^ fy[i][l0][l1][l2][r0][r1][r2] << endl;
                                            return 0;
                                        }
                                        for (int x = 0; x < 2; x++) {
                                            for (int y = 0; y < 2; y++) {
                                                int z = x ^ y;
                                                if ((x < ll[i]) && (!l0)) {
                                                    continue;
                                                }
                                                if ((y < ll[i]) && (!l1)) {
                                                    continue;
                                                }
                                                if ((z < ll[i]) && (!l2)) {
                                                    continue;
                                                }
                                                if ((x > rr[i]) && (!r0)) {
                                                    continue;
                                                }
                                                if ((y > rr[i]) && (!r1)) {
                                                    continue;
                                                }
                                                if ((z > rr[i]) && (!r2)) {
                                                    continue;
                                                }
                                                f[i + 1][l0 | (x > ll[i])][l1 | (y > ll[i])][l2 | (z > ll[i])][r0 | (x < rr[i])][r1 | (y < rr[i])][r2 | (z < rr[i])] = 1;
                                                fx[i + 1][l0 | (x > ll[i])][l1 | (y > ll[i])][l2 | (z > ll[i])][r0 | (x < rr[i])][r1 | (y < rr[i])][r2 | (z < rr[i])] = fx[i][l0][l1][l2][r0][r1][r2] * 2 + x;
                                                fy[i + 1][l0 | (x > ll[i])][l1 | (y > ll[i])][l2 | (z > ll[i])][r0 | (x < rr[i])][r1 | (y < rr[i])][r2 | (z < rr[i])] = fy[i][l0][l1][l2][r0][r1][r2] * 2 + y;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        puts("1");
        if (lt % 2 == 1) {
            lt++;
        }
        cout << 2 << endl;
        cout << lt << " " << lt + 1 << endl;
        return 0;
    }
    if (l + 4 <= r) {
        cout << 0 << endl;
        cout << 4 << endl;
        if (l % 2 == 1) {
            l++;    
        }
        cout << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
        return 0;
    }
    brute();
}