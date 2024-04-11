#include <bits/stdc++.h>
using namespace std;
int a[15],n,m;
int main() {
    cin >> n >> m;
    function<int(int)> f = [&f](int n){return (n == 0)?1:f(n-1)*n;};
    cout << f(min(n,m)) << endl;
    return 0;
}