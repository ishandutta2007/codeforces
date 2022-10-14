#include <bits/stdc++.h>
#define ff(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define fb(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    ff(i,0,n-1) cin >> a[i];
    int ind = 0;
    ff(i,1,n-1){
        if(a[i] < a[i-1]) break;
        ind = i;
    }
    ff(i,ind+2,n-1){
        if(a[i] < a[i-1]){
            cout << -1;
            return 0;
        }
    }
    if (ind < n - 1 && a[0] < a[n-1]) {
        cout << -1;
        return 0;
    }

    cout << n - ind - 1;
    return 0;
}