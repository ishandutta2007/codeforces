#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll A, B;
    cin >> A >> B;

    ll S = A + B;
    ll K;
    for (K = 1e6; K * (K + 1) / 2 > S; --K) {};
    // 1+2+...+K <= A+B

    vector<int> a, b;
    for (int i = K; i > 0; --i) {
        if (A >= i) {
            a.push_back(i);
            A -= i;
        } else if (B >= i) {
            b.push_back(i);
            B -= i;
        }
    }

    cout << a.size() << endl;
    for (int c : a) cout << c << " ";
    cout << endl;

    cout << b.size() << endl;
    for (int c : b) cout << c << " ";
    cout << endl;
    return 0;
}