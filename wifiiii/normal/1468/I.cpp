#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y;
ll solve(ll p, ll q, ll r, ll s)
{
    if(r < 0) r = -r, s = -s;
    if(p < 0) p = -p, q = -q;
    if(p == 0)
    {
        x = abs(r);
        y = abs(q);
        return abs(r * q);
    }
    s = s - r / p * q;
    r = r - r / p * p;
    return solve(r, s, p, q);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        ll g = solve(p, q, r, s);
        if(g != n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for(int i=0;i<x;++i)
            {
                for(int j=0;j<y;++j)
                {
                    cout << i << " " << j << '\n';
                }
            }
        }
    }
}