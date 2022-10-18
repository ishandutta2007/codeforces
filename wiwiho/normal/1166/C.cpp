#include <bits/stdc++.h>

using namespace std;

//#define TEST
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    sort(a.begin(), a.end());

    long long ans = 0;

    for(auto it = a.begin(); it < a.end(); it++){
        int aa = abs(*it);
        int ab = abs(2 * aa);
        auto it2 = upper_bound(a.begin(), a.end(), ab);
        ans += it2 - it - 1;
    }

    cout << ans << "\n";
    
    return 0;
}