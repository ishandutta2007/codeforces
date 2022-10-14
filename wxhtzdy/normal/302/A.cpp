#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
using namespace std;

#define gas 0

// 80 strana iz srpskog rip...

int a[200005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(gas);


    int n, q;
    cin >> n >> q;
    map<int, int> kaunt;
    ff(i,1,n){
        cin >> a[i];
        kaunt[a[i]]++;
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << ((r % 2 != l % 2) && (kaunt[1] > (r - l) / 2 && kaunt[-1] > (r - l) / 2) ? 1 : 0) << "\n";
    }
    return 0;
}