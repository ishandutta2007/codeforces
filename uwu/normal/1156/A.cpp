#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

/*
1. circle;
2. isosceles triangle with the length of height equal to the length of base;
3. square.
*/

void bad(){
    cout << "Infinite" << '\n';
    exit(0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    cin >> a[1];
    int ans = 0;
    for (int i = 2; i <= n; ++i){
        cin >> a[i];
        if (a[i - 1] == 1 && a[i] == 2) ans += 3;
        if (a[i - 1] == 1 && a[i] == 3) ans += 4;
        if (a[i - 1] == 2 && a[i] == 1) ans += 3;
        if (a[i - 1] == 2 && a[i] == 3) bad();
        if (a[i - 1] == 3 && a[i] == 1) ans += 4;
        if (a[i - 1] == 3 && a[i] == 2) bad();
    }
    for (int i = 3; i <= n; ++i){
        if (a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) ans--;
    }
    cout << "Finite" << '\n';
    cout << ans << '\n';
}