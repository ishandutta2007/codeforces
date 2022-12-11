#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 3;
bool poss[MAX_N];

void f1(int n) {
    int old = n, i = 2;
    vector <int> now;
    while (i * i <= n) {
        if ((n % i) == 0) {
            now.push_back(i);
            while ((n % i) == 0) {
                n /= i;
            }
        }
        i++;
    }
    if (n != 1) {
        now.push_back(n);
    }
    n = old;
    int prev;
    for (int elem : now) {
        prev = max(elem, n - elem) + 1;
        for (int j = prev; j <= n; j++) {
            poss[j] = 1;
        }
    }
}

int f2(int n) {
    int old = n, i = 2;
    vector <int> now;
    while (i * i <= n) {
        if ((n % i) == 0) {
            now.push_back(i);
            while ((n % i) == 0) {
                n /= i;
            }
        }
        i++;
    }
    if (n != 1) {
        now.push_back(n);
    }
    n = old;
    int ret = n;
    for (int elem : now) {
        ret = min(ret, max(elem + 1, n - elem + 1));
    }
    return ret;
}


int main() {
    int x;
    cin >> x;
    for (int i = 3; i <= MAX_N; i++) {
        poss[i] = 0;
    }
    f1(x);
    int ans = x;
    for (int i = 3; i <= x; i++) {
        if (poss[i]) {
            ans = min(ans, f2(i));
        }
    }
    cout << ans << endl;
    return 0;
}