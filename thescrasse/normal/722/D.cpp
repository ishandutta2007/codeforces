// 1322B
// xor delle somme a coppie

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, y[50010];
priority_queue<long long> pq;
map<long long, long long> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        y[i] = a;
        f[a]++;
        pq.push(a);
    }

    while (true) {
        a = pq.top();
        res = a;
        f[a]--;
        // cout << res << endl;
        pq.pop();
        a /= 2;
        while (f[a] != 0 && a != 0) {
            a /= 2;
        }
        // cout << "a = " << a << endl;
        if (a == 0) {
            break;
        } else {
            pq.push(a);
            f[a]++;
        }
    }

    // cout << res << endl;

    while (!pq.empty()) {
        pq.pop();
    }
    f.clear();

    for (i = 0; i < n; i++) {
        pq.push(y[i]);
        f[y[i]]++;
    }

    while (true) {
        a = pq.top();
        if (a == res) {
            break;
        }
        pq.pop();
        a /= 2;
        while (f[a] != 0 && a != 0) {
            a /= 2;
        }
        if (a == 0) {
            break;
        } else {
            pq.push(a);
            f[a]++;
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}