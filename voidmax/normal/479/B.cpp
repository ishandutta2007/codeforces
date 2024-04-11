#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

int n, need, z, k, last;
int ans[101], arr[101];
bool used[101];

int maxi() {
    int ans = -1, inter = -1;
    for (int i = 0; i < n; ++i) {
        if (!used[i] && (arr[i] > inter)) {
            ans = i;
            inter = arr[i];
        }
    }
    return ans;
}

int mini() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < arr[ans]) {
            ans = i;
        }
    }
    return ans;
}

bool check(int need, bool a) {
    int c;
    bool f = false;
    for (int i = 0; i < 101; ++i) {
        arr[i] = ans[i];
        used[i] = false;
    }
    for(c = 0; c < k + 1; c++) {
        int ma = maxi(), mi = mini();
        if (ma != -1 && (arr[ma] - arr[mi]) > need) {
            used[mi] = true;
            if (a) cout << ma + 1 << ' ' << mi + 1 << endl;
            arr[ma]--;
            arr[mi]++;
        }
        else {
            int maxin = -1, minin = 10e9;
            for (int i = 0; i < n; ++i) {
                maxin = max(maxin, arr[i]);
                minin = min(minin, arr[i]);
            }
            f = (maxin - minin) <= need;
            break;
        }
    }
    last = c;
    return f;
}

main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> ans[i];
        z += ans[i];
    }
    int L = -1, R = 10e9, M;
    while (R - L > 1) {
        M = (R + L) / 2;
        if (check(M, 0)) {
            R = M;
        }
        else {
            L = M;
        }
    }
    check(R, 0);
    cout << R << ' ' << last << endl;;
    check(R, 1);
}