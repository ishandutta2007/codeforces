#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll brojac = 0;
    ll n;
    cin >> n;
    ll niz[n];
    vector<ll> parni;
    vector<ll> neparni;
    for(int i = 0; i < n; i++)
    {
        cin >> niz[i];
        brojac += niz[i];
        if(niz[i] % 2 == 0) parni.pb(niz[i]);
        else neparni.pb(niz[i]);
    }
    sort(parni.begin(), parni.end());
    sort(neparni.begin(), neparni.end());
    ll tr = 0;
    reverse(parni.begin(), parni.end());
    reverse(neparni.begin(), neparni.end());
    ll k = -1;
    for(int i = 0; i < min(parni.size(), neparni.size()); i++)
    {
        tr += parni[i]+neparni[i];
        k = i;
    }
    if(parni.size() > neparni.size()) tr += parni[k+1];
    else if(parni.size() < neparni.size()) tr += neparni[k+1];
    cout << brojac-tr;
    return 0;
}