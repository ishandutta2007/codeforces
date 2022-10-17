#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    auto ask = [&](int x) {
        assert(1 <= x && x <= n - 1);
        cout << "+ " << x << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    int pre = 0, cur = 0;
    int lo = 1, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2, c = n - (mid + cur) % n;
        if(c == n) --c;
        int tmp = ask(c);
        if(tmp != pre) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
        cur += c;
        pre = tmp;
    }
    int ans = cur + lo - 1;
    cout << "! " << ans << endl;
}