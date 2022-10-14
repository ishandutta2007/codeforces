#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
using namespace std;

#define gas 0

// 80 strana iz srpskog rip...
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(gas);

    int a, b;
    cin >> a >> b;

    if(a > b)swap(a, b);

    int ans = 0;
    ff(i,1,10000){
        if(a < b){
            ans += i;
            a++;
        }
        if(a < b){
            ans += i;
            a++;
        }
    }

    cout << ans; // skrrr

    return 0;
}