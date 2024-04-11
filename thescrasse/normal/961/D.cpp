// 961D
// determinare se i punti dati passano per due rette

#include <bits/stdc++.h>
using namespace std;

#define INF 1e10

long long i, i1, j, k, k1, t, n, d, m, res, check1, a, b, x[100010], y[100010];
vector<long long> rem;
pair<long long, long long> sl;

pair<long long, long long> gcd(long long a, long long b) {
    long long s, a1, b1;
    s = 1;
    if (a == 0) {
        return {0, 69420};
    }
    if (b == 0) {
        return {69420, 0};
    }
    if (a < 0) {
        s *= -1;
        a *= -1;
    }
    if (b < 0) {
        s *= -1;
        b *= -1;
    }
    a1 = a;
    b1 = b;
    while (a != b) {
        if (a > b) {
            a = ((a + b - 1) % b) + 1;
        } else {
            b = ((b + a - 1) % a) + 1;
        }
    }
    a1 /= a;
    b1 /= a;
    b1 *= s;
    return {a1, b1};
}

pair<long long, long long> slope(int a, int b) {
    long long n, d;
    long double sl;
    n = y[a] - y[b];
    d = x[a] - x[b];
    return gcd(n, d);
}

void pdb(pair<long long, long long> p) {
    cout << "[" << p.first << " " << p.second << "]" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (i = 0; i < 3; i++) {
        rem.clear();
        if (i == 0) {
            a = 1;
            b = 0;
        } else if (i == 1) {
            a = 2;
            b = 0;
        } else {
            a = 2;
            b = 1;
        }
        sl = slope(a, b);
        // cout << a << ' ' << b << ' ' << endl;
        // pdb(sl);

        for (j = 0; j < n; j++) {
            if (j != b) {
                // cout << j << ' ' << b << ' ' << endl;
                // pdb(slope(j, b));
                if (slope(j, b) != sl) {
                    rem.push_back(j);
                }
            }
        }

        if (rem.size() < 3) {
            cout << "YES";
            return 0;
        }

        a = rem[0];
        b = rem[1];
        sl = slope(a, b);
        // cout << a << ' ' << b << ' ' << endl;
        // pdb(sl);
        check1 = 1;
        for (j = 2; j < rem.size(); j++) {
            if (slope(rem[j], b) != sl) {
                check1 = 0;
                break;
            }
        }

        if (check1 == 1) {
            cout << "YES";
            return 0;
        } else {
            continue;
        }
    }

    cout << "NO";

    return 0;
}