#include <bits/stdc++.h>
typedef int ll;
using namespace std;
ll i,j,k,n,l,r,x;
bitset<3005> a;
bitset<3005> d, e;
int main() {
 	l = 1005, r = -1;
    cin >> k >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        a[x] = 1;
        l = min(x, l);
        r = max(x, r);
    }
    if (k < l || k > r)
    {
        cout << -1 << endl;
        return 0;
    }
    d[1500] = 1;
    for (i = 1; i <= 1002; i++)
    {
        e.reset();
        for (j = 0; j < 3000; j++)
            if (d[j] == 1)
                e |= (a<<(j-k));
        d = e;
        if (d[1500] == 1)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}