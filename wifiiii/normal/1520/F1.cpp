#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}
int main() {
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int lo = 1, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(mid - ask(1, mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    cout << "! " << lo << endl;
}