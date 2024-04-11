#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int ask(int x) {
    int ret;
    cout << "? " << x << endl;
    cin >> ret;
    return ret;
}
int main() {
    int n;
    cin >> n;
    int lo = 1, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        int l = ask(mid);
        int r = ask(mid + 1);
        if(l > r) {
            lo = mid + 1;
        } else if(l < r) {
            hi = mid;
        }
    }
    cout << "! " << lo << endl;
}
// 1 2 3