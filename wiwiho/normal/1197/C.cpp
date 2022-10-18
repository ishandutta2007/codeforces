#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))

typedef long long ll;

using namespace std;


int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> d(n - 1);
    ll sum = 0;
    for(int i = 0; i < n - 1; i++) d[i] = a[i + 1] - a[i], sum += d[i];
    gsort(d);
    for(int i = 0; i < k - 1; i++) sum -= d[i];

    cout << sum << "\n";

    return 0;
}