#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
using namespace std;

int n,a[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    long long x = 0, y = 0;
    ff(i,1,n){
        cin >> a[i];
        x = max(x, x + a[i]);
        y = min(y, y + a[i]);
    }
    cout << x - y;
}