#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        ll npom = n;
        ll brojac = 0;
        //ll k = 1;
        while(npom % 3 == 0)
        {
            npom /= 3;
            brojac += 2;
        }
        while(npom % 5 == 0)
        {
            npom /= 5;
            brojac += 3;
        }
        while(npom % 2 == 0)
        {
            npom /= 2;
            brojac++;
        }
        if(npom == 1) cout << brojac << "\n";
        else cout << -1 << "\n";
    }
}