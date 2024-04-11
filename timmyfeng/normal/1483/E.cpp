#include <bits/stdc++.h>
using namespace std;

const long long MAX_M = 100000000000000LL;
const int MAX_QUERIES = 105;

long long cache[MAX_QUERIES][MAX_QUERIES];
int queries_left;

bool query(long long x) {
    if (x > MAX_M) {
        return false;
    }

    --queries_left;
    cout << "? " << x << endl;
    string res;
    cin >> res;
    return res == "Lucky!";
}

long long add(long long l, long long r) {
    return l <= LLONG_MAX - r ? l + r : LLONG_MAX;
}

long long span(int queries, int balance) {
    if (cache[queries][balance] == 0) {
        long long &ans = cache[queries][balance];
        if (queries == 0) {
            ans = 1;
        } else if (balance <= 1) {
            ans = span(queries - 1, balance + 1);
        } else {
            ans = add(span(queries - 1, balance - 2), span(queries - 1, balance + 1));
        }
    }
    return cache[queries][balance];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        queries_left = MAX_QUERIES;

        long long balance = 1;
        while (query(balance)) {
            balance *= 2;
        }

        long long low = balance / 2, high = balance - 1;
        balance = 0;

        while (low < high) {
            while (balance <= 1) {
                query(low);
                ++balance;
            }

            long long mid = low + min(high - low, span(queries_left - 1, balance - 2));
            if (query(mid)) {
                ++balance;
                low = mid;
            } else {
                balance -= 2;
                high = mid - 1;
            }
        }

        cout << "! " << high << endl;
    }
}