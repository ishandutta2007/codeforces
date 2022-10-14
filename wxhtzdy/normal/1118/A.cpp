#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int brojac[6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        cout << min(n*a, n/2*b+n%2 * a) << "\n";
    }
}