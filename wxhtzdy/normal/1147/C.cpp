#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))

using namespace std;

int n;
int niz[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ff(i,1,n)cin >> niz[i];
    int mn = 1e9;
    ff(i,1,n)mn = min(mn, niz[i]);
    int cnt = 0;
    ff(i,1,n)if(niz[i] == mn)cnt++;
    cout << (cnt <= n / 2 ? "Alice" : "Bob");
    return 0;
}