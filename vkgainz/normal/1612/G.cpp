#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#include <numeric>

using namespace std;

void restore(vector<long long> &v) {
    for (int i = 2000001; i >= 0; i--) {
        v[i] += v[i + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    vector<long long> fac(2000005);
    fac[0] = 1LL;
    long long MOD = 1e9 + 7;
    for (int i = 1; i <= 2000004; i++) {
        fac[i] = fac[i - 1] * 1LL * i % MOD;
    }
    int numZer = 0;
    vector<int> c(m);
    vector<long long> negEven(2000005), negOdd(2000005);
    vector<long long> posEven(2000005), posOdd(2000005);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        if (c[i] % 2 == 1) {
            ++numZer;
        }
        int st = -c[i] + 1;
        //we can use prefix updates and then restore!!
        if (c[i] % 2) {
            //do some easy prefix operations
            ++negEven[-st / 2];
            ++posEven[-st / 2];
        } else {
            //do some easy prefix operations
            ++negOdd[(-st + 1) / 2];
            ++posOdd[(-st + 1) / 2];
        }
    }
    long long ans = fac[numZer] % MOD;
    restore(negEven), restore(negOdd);
    restore(posEven), restore(posOdd);
    for (int i = 1; i <= 2000000; i++) {
        ans *= fac[negEven[i]] % MOD;
        ans %= MOD;
        ans *= fac[negOdd[i]] % MOD;
        ans %= MOD;
        ans *= fac[posEven[i]] % MOD;
        ans %= MOD;
        ans *= fac[posOdd[i]] % MOD;
        ans %= MOD;
    }
    vector<long long> numNeg(2000005);
    vector<long long> numPos(2000005);
    for (int i = 1; i <= 1000000; i++) {
        numNeg[2 * i] = negEven[i];
        numNeg[2 * i - 1] = negOdd[i];
        numPos[2 * i] = posEven[i];
        numPos[2 * i - 1] = posOdd[i];
    }
    long long cost = 0LL;
    //neg
    long long currPos = 1;
    long long inv = (MOD + 1) / 2;
    for (int i = 2000001; i >= 1; i--) {
        long long sub = i * 1LL * numNeg[i] % MOD;
        sub %= MOD;
        sub *= (currPos * 1LL * 2 + numNeg[i] - 1) % MOD;
        sub %= MOD;
        sub *= inv;
        sub %= MOD;
        cost -= sub;
        cost %= MOD;
        currPos += numNeg[i];
        currPos %= MOD;
    }
    //pos
    currPos += numZer;
    for (int i = 1; i <= 2000001; i++) {
        long long add = i * 1LL * numPos[i] % MOD;
        add %= MOD;
        add *= (currPos * 1LL * 2 + numPos[i] - 1) % MOD;
        add %= MOD;
        add *= inv;
        add %= MOD;
        cost += add;
        cost %= MOD;
        currPos += numPos[i];
        currPos %= MOD;
    }
    if (cost < 0) cost += MOD;
    if (ans < 0) ans += MOD;
    cout << cost << " " << ans << "\n";

}