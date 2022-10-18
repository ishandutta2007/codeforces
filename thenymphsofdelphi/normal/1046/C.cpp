#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a[200001], b[200001], c = 0, d = 1, c2;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    a[m] += b[1];
    for(int i = 1; i <= n; i++) if(i != m) a[i] += b[n];
    for(int i = 1; i <= n; i++) if(a[i] > a[m]) c++;
    for(int i = 1; i <= n; i++) if(i != m) a[i] -= b[n];
    c2 = c;
    c = m;
    for(int i = m - 1; i > c2; i--){
        d++;
        while(a[i] + b[d] > a[m] && d <= n) d++;
        if(d > n){
            cout << c;
            return 0;
        }
        else c--;
    }
    cout << c;
    return 0;
}