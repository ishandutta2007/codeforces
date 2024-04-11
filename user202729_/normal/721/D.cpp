// http://codeforces.com/contest/721/problem/D


#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>

typedef long long ll;
/*
int signum (ll x) {
    return x ? (x > 0 ? 1 : -1) : 0;
}
*/
int n, k, x, nzero = 0, // number of 0 in a[i]
prodnonzerosign = 1, prodsign;
ll a [200000];
bool firstneg;

ll abs(ll x) {return x < 0 ? -x : x;} // cannot handle x =
// std::numeric_limit<ll>::min()

struct num{
    ll value;
    int index;
    num(ll val1, int id1) : value (val1), index (id1) {}
};

bool operator<(num x, num y) {
    return abs(x.value) > abs(y.value);
} // the largest element is the element with smallest value magnitude

int main() {
    std::cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i]) {
            if (a[i]<0) {
                prodnonzerosign = - prodnonzerosign;
            }
        } else {
            ++nzero;
        }
    }

    if (nzero) {
        if (nzero > k) {
            std::cout << a[0];
            for (int i = 1; i < n; ++i)
                std::cout << " " << a[i];
            std::cout << "\n";
            return 0; // the product will always be 0 whatever we do
        } else {
            k -= nzero; // use n operations to unzero those
            firstneg = 1 == prodnonzerosign;
            // if the product of nonzero elements is positive, we let
            // one of the zero elements to be negative, so the new product
            // will be negative.
            for (int i = 0; i < n; i++)
                if (0 == a[i]) {
                    a[i] = firstneg ? -x : x;
                    firstneg = false; // only do that to one element
                }
            // anyway, now the product is negative. Only k operations left.
            prodsign = -1;
        }
    } else prodsign = prodnonzerosign;

    // use a PQ (STL) to pick smallest absolute element
    std::priority_queue<num> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(a[i], i);
    }

    int id, sign;
    while (k --> 0) {
        id = pq.top().index;
        sign = prodsign * (a[id]>0?-1:1);// negative sign product
        // we are supposed to execute:
        a[id] += sign * x;
        if (a[id] == 0) {
            if (k) {
                a[id] += sign * x;
                --k;
            }
        }
        prodsign = sign * (a[id]>0?-1:1);
        // latter part = -signum(a[id]) unless k==0
        pq.pop();
        pq.emplace(a[id], id);
    }

    std::cout << a[0];
    for (int i = 1; i < n; ++i)
        std::cout << " " << a[i];
    std::cout << "\n";
}