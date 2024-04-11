#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define pii pair <char. int>
#define LL long long
using namespace std;

const int N = 200005;
LL a[N];

int main () {
    LL n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a+ 1 + n);
    if (a[1] == a[n]){
        cout << 0 << ' ' << n * (n - 1) / 2;
        return 0;
    }
    LL mn = 0, mx = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == a[1]) mn++;
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == a[n]) mx++;
    }
    cout << a[n] - a[1] << ' ' << mx * mn;
}