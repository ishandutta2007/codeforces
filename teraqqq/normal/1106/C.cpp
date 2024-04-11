#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;

int n, a[N];
long long res = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
    	cin >> a[i];
    sort(a, a+n);

    for(int i = 0, j = n-1; i < j; ++i, --j)
    	res += (a[i]+a[j])*(a[i]+a[j]);
    cout << res;
}