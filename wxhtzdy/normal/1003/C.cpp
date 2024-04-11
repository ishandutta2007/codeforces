#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double mx = 0;
    int n, k;
    cin >> n >> k;
    double niz[n+1];
    double prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> niz[i];
        prefix[i] = prefix[i-1]+niz[i];
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = i+k; j <= n; j++)
        {
            mx = max(mx, (prefix[j]-prefix[i])/(j-i));
        }
    }
    cout << fixed << setprecision(8) << mx;
    return 0;
}