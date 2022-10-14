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
    int niz[n];
    pair<int, int> par[n];
    for(int i = 0; i < n; i++)
        cin >> par[i].second >> par[i].first;
    ll brojac = 0;
    for(int i = 0; i < n; i++)
        brojac += par[i].second;
    for(int i = 0; i < n; i++)
        niz[i] = abs(par[i].first - par[i].second);
    sort(niz, niz+n);
    reverse(niz, niz+n);
    int rez = 0;
    for(int i = 0; i < n; i++)
    {
        if(brojac <= m)
        {
            cout << rez;
            return 0;
        }
        rez++;
        brojac -= niz[i];
    }
    if(brojac <= m)
    {
        cout << rez;
        return 0;
    }
    cout << -1;
    return 0;
}