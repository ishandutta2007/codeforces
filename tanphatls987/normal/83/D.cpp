#include <bits/stdc++.h>

using namespace std;

bool isPrime(int k) {
    for(int use = 2; use * use <= k; use++) if (k % use == 0)
        return 0;
    return 1;
}
const int N = 1e7 + 10;
int tr[N];
int R, L;


long long get(int k) {
    return R / k - (L - 1) / k;
}
long long DFS(vector<int> &pri, int i, int prod, int sign) {
    if (i == pri.size()) return 0;
    long long ans = DFS(pri, i + 1, prod, sign);
    if (prod <= R / pri[i]) {
        prod *= pri[i];
        sign *= -1;
        ans += sign * get(prod) + DFS(pri, i + 1, prod, sign);
    }
    return ans;
}
int main() {
    int k;
    cin >> L >> R >> k;
    if (!isPrime(k)) {
        cout << 0;
        return 0;
    }
    if (1LL * k * k > R) {
        cout << (L <= k && k <= R);
        return 0;
    }
    if (k >= 200) {
        for(int i = 2; i < k; i++) if (!tr[i]) 
            for(int j = i; j <= R / k; j += i)
                tr[j] = 1;
        cout << count(tr + ((L + k - 1) / k), tr + (R / k) + 1, 0);
        return 0;
    }
    vector<int> pri;
    for(int i = 2; i < k; i++) if (!tr[i]) {
        pri.push_back(i);
        for(int j = i; j < k; j += i) tr[j] = 1;
    }
    cout << get(k) + DFS(pri, 0, k, 1); 
}