#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n;
int a[N], tr[N];
long long f[N];

int sign(int x) {
    if (x == 0) return x;
    return x / abs(x);
}
void prepare() {
    cin >> n;
    for(int i = 2; i <= n + 1; i++) cin >> a[i];
    
    int tmpn = n + 1; 
    n = 1;
    for(int en = 2; en <= tmpn;) {
        int st = en;
        while (en <= tmpn && a[en] == a[st]) en++;
        for(int i = 1; i <= min(2, en - st); i++) a[++n] = a[st];
    }


    a[1] = a[2];
    tr[2] = 1;
    for(int i = 3; i <= n; i++) {
        if (sign(a[i] - a[i - 1]) == sign(a[i - 1] - a[i - 2]))
            tr[i] = tr[i - 1];
        else tr[i] = i - 1;
    }
    //for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << '\n';
    //for(int i = 1; i <= n; i++) cout << tr[i] << " "; cout << '\n';
}
long long solve() {
    for(int i = 2; i <= n; i++) f[i] = max(f[tr[i] - 1] + abs(a[i] - a[tr[i]]), f[tr[i]] + abs(a[i] - a[tr[i] + 1]));
    return f[n];
}
int main() {
    prepare();
    cout << solve();
}