#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;
ll n, m, k;
int min(int a, int b) {
    return a < b ? a : b;
}
bool works(ll max) {
    ll num=0;
    for(int i=1;i<=n;i++) num += min(max/i,m);
    return num >= k;
}
int main() {
    cin >> n >> m >> k;

    ll l = 1, r = (n*m)+1;
    while(l < r) {
        ll mid = (l + r) / 2;
        if(works(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << "\n";
}