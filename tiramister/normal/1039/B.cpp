#include <iostream>
#include <random>
#include <string>

using namespace std;
using ll = long long;

ll n, k, l, r;
random_device rnd;

// Narrow the possible area of the train
void half() {
    ll mid = (r + l) / 2;
    cout << l << " " << mid << endl;

    string res;
    cin >> res;

    if (res == "Yes") {
        l = max(1LL, l - k);
        r = min(n, mid + k);
    } else if (res == "No") {
        l = max(1LL, mid - k + 1);
        r = min(n, r + k);
    }

    return;
}

// Choose a number in [l, r] randomly
void gamble() {
    static mt19937_64 mt(rnd());

    ll point = mt() % (r - l + 1) + l;
    cout << point << " " << point << endl;

    string res;
    cin >> res;

    if (res == "Yes") {
        exit(0);
    } else if (res == "No") {
        l = max(1LL, l - k);
        r = min(n, r + k);
    }

    return;
}

int main() {
    cin >> n >> k;

    l = 1, r = n;
    // the train is in [l, r]

    for (ll i = 0; i < 4500; ++i) {
        if (r - l > 50) {
            half();
        } else {
            // in testcase 138, only this side is called
            // because always [l, r] = [1, 10].
            gamble();
        }
    }

    // cout << "Too unlucky....? :(" << endl;
    return 0;
}