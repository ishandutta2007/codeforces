#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int mx = 100000;
long long k;

long long num, flag;

long long g[1000100], gi = 0;

void init (long long n) {
    for (long long i = 1; i * i <= n; i++)
        if (n % i == 0) g[++gi] = i;
    for (long long i = (int)(sqrt(n) + 1e-6); i >= 1; i--)
        if (n % i == 0 && i * i != n) g[++gi] = n / i;
}

void dfs (long long n, long long d){
    int t = 0;
//    cout << "n: " << n << "  d: " << d << endl;
    if (d == k) {
        cout << ' ' << n;
        if ((++num) == mx) flag = 1;
        return;
    }
    if (n == 1)
    {
        cout << ' ' << 1;
        if ((++num) == mx) flag = 1;
        return;
    }
//    if (n == 1) return;
    for (long long i = 2; i <= gi; i++){
        if (g[i] == n) break;
        if (n % g[i] == 0){
    //        cout << ' ' << i;
            t = 1;
            break;
        }
    }
    if (t == 0){
        for (int i = 1; i <= k - d; i++){
            cout << ' ' << 1;
            if ((++num) == mx) {flag = 1; return;}
        }
        cout << ' ' << n;
        if ((++num) == mx) {flag = 1; return;}
        return;
    }
    for (long long i = 1; i <= gi; i++){
        if (g[i] > n) break;
        if (n % g[i] == 0){
    //        cout << ' ' << i;
            dfs(g[i], d + 1);
            if (flag) return;
        }
    }
//    cout << endl;
}

int main () {
//    freopen ("out.txt", "w", stdout);
    long long n;
    while (cin >> n >> k){
        gi = 0;
        init (n);
//        for (int i = 1; i <= gi; i++)
//            cout << g[i] << ' ';cout<<endl;
        if (k >= 100000 && n != 1)
        {
            cout << 1;
            for (int i = 1; i < 100000; i++)
                cout << ' ' << 1;
            continue;
        }
        k = min(k, (long long)100000);
        if (k == 0) {
                cout << n << endl;
                continue;
        }
        flag = 0;
        num = 1;
        cout << 1;
        for (long long i = 2; i * i <= n; i++)
            if (n % i == 0) {
                dfs(i, 1);
                if (flag) break;
            }
        for (long long i = ((int)sqrt(n) + 1e-6); i  >= 1; i--)
        if (n % i == 0 && i * i != n){
            if (flag) break;
            dfs(n / i, 1);
            if (flag) break;
        }
//        cout << num << endl;
        cout << endl;
//        break;
    }
}