#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int l[n], r[n];
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<int> brojac;
    for(int i = 1; i <= m; i++)
    {
        bool b = true;
        for(int j = 0; j < n; j++)
        {
            if(l[j] <= i && r[j] >= i) b = false;
        }
        if(b) brojac.pb(i);
    }
    cout << brojac.size() << "\n";
    for(int i = 0; i < brojac.size(); i++)
        cout << brojac[i] << " ";
    return 0;
}