#include<bits/stdc++.h>
using namespace std;

int main(){
    long long l1, r1, l2, r2, x, l, r, ans;
    cin >> l1 >> r1 >> l2 >> r2 >> x;
    l = max(l1, l2);
    r = min(r1, r2);
    ans = r - l + 1;
    if (x >= l && x <= r){
        ans--;
    }
    cout << max(ans, 0LL);
}