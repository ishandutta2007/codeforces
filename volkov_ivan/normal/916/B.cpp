#include <iostream>
#include <vector>
#include <map>

using namespace std;

const long long one = 1;

int main() {
    map <int, int> a;
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i <= 60; i++) {
        if (((n & (one << i)) != 0)) {
            a[i]++;
            k--;
        }
    }
    if (k < 0) {
        cout << "No" << endl;
        return 0;
    }
    int now;
    for (int rest = k; rest >= 1; rest--) {
        now = (*(--a.end())).first;
        if (a[now] > rest) {
            now = (*a.begin()).first;
        }
        a[now]--;
        if (a[now] == 0) a.erase(now);
        a[now - 1] += 2;
    }
    cout << "Yes" << endl;
    for (auto uk = --a.end(); uk != a.begin(); uk--) {
        for (int i = 0; i < (*uk).second; i++) {
            cout << (*uk).first << ' ';
        }
    }
    auto uk = a.begin();
    for (int i = 0; i < (*uk).second; i++) {
        cout << (*uk).first << ' ';
    }
    cout << endl;
    return 0;
}