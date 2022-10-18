#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int w, m;
vector<ll> powW;
ll curBalance;
bool found;

void balance(int i) {
    if (i == powW.size()) {
        if (curBalance == m)
            found = true;
        return;
    }

    for(int j = -1; j <= 1; ++j) {
        curBalance += j*powW[i];
        balance(i+1);
        curBalance -= j*powW[i];
    }
}

int main() {
    scanf("%d%d", &w, &m);
    if (w == 2 || w == 3) {
        puts("YES");
        return 0;
    }

    ll sum = 0, curPow = 1;
    while (sum + m >= curPow) {
        sum += curPow;
        powW.push_back(curPow);
        curPow *= w;
    }

    found = false;
    balance(0);

    puts((found) ? "YES" : "NO");

    return 0;
}