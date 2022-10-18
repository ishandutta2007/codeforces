#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

bool isEqual(int n, long long a[], long long b[]) {
    for(int i = 0; i < n; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

bool isIncreasing(int n, long long a[]) {
    for(int i = 1; i < n; ++i)
        if (a[i-1] >= a[i])
            return false;
    return true;
}

void reversePrefix(int n, long long a[]) {
    for(int i = n-1; i >= 1; --i)
        a[i] -= a[i-1];
}

int n;
long long a[MAXN], b[MAXN];

string solve() {
    if (n == 1 && a[0] != b[0])
        return "-1";

    string ans;

    while (!isEqual(n, a, b)) {
        reverse(b, b+n);
        if (isEqual(n, a, b)) {
            ans += 'R';
            return ans;
        }
        reverse(b, b+n);

        if (isIncreasing(n, b)) {
            reversePrefix(n, b);
            ans += 'P';
        } else {
            reverse(b, b+n);
            ans += 'R';
            if (!isIncreasing(n, b))
                return "-1";
            else {
                reversePrefix(n, b);
                ans += 'P';
            }
        }
    }

    return ans;
}

long long calc() {
    long long a0 = a[0], a1 = a[1];
    long long b0 = min(b[0], b[1]), b1 = max(b[0], b[1]);

    long long sum = 0;
    while (b0 != 0) {
        if (a0 == b0 && (b1 - a1) % b0 == 0)
            return sum + (b1 - a1) / b0;
        if (a1 == b0 && (b1 - a0) % b0 == 0)
            return sum + (b1 - a0) / b0;

        sum += b1 / b0;
        long long c = b1 % b0;
        b1 = b0;
        b0 = c;

        if (b0 > b1)
            swap(b0, b1);
    }

    return -1;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    if (n == 2) {
        long long x = calc();
        if (x > 2e5) {
            puts("BIG");
            printf("%lld\n", x);
            return 0;
        } else if (x == -1) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }

    if (n == 1 && a[0] != b[0]) {
        puts("IMPOSSIBLE");
        return 0;
    }

    string ans = solve();
    if (ans == "-1") {
        puts("IMPOSSIBLE");
        return 0;
    }

    int cntP = 0;
    for(char c: ans)
        if (c == 'P')
            ++cntP;
    if (cntP > 2e5) {
        puts("BIG");
        printf("%d\n", cntP);
        return 0;
    }

    reverse(ans.begin(), ans.end());
    puts("SMALL");
    printf("%d\n", ans.size());
    cout << ans << endl;

    return 0;
}