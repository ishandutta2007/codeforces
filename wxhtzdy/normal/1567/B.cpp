#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
using namespace std;


int ksor[1000005];

void solve(){
    int a,b; cin >> a >> b;
    int xr = ksor[a - 1];
    if(xr == b){
        cout << a << "\n";
    }
    else{
        cout << (((xr ^ b) == a) ? a + 2 : a + 1) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ff(i,1,1000000)ksor[i] = ksor[i - 1] ^ i;
    int tt;
    cin >> tt;
    while(tt--)solve();
    return 0;
}