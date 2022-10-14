#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
            cin >> a[i];
    }
    sort(a,a + n);
    if(k == 0)
    {
        if(a[0] >= 2) {
            cout << 1;
            return 0;
        } else {
            cout << -1;
            return 0;
        }
    }
    else
    {
        if(a[k] == a[k-1]) {
            cout << -1;
            return 0;
        } else {
            cout << a[k-1];
        }
    }
}