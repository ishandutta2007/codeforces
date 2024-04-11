#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool b = true;
    vector<int> opadajuci;
    int n;
    cin >> n;
    int niz[n];
    for(int i = 0; i < n; i++)
        cin >> niz[i];
    sort(niz, niz+n);
    for(int i = 1; i < n; i++)
        if(niz[i] == niz[i-1]) opadajuci.pb(niz[i]);
    for(int i = 1; i < opadajuci.size(); i++)
        if(opadajuci[i] == opadajuci[i-1]) b = false;
    if(!b)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << n-opadajuci.size() << "\n" << niz[0] << " ";
    for(int i = 1; i < n; i++)
        if(niz[i] > niz[i-1]) cout << niz[i] << " ";
    cout << "\n";
    reverse(opadajuci.begin(), opadajuci.end());
    cout << opadajuci.size() << "\n";
    for(int i = 0; i < opadajuci.size(); i++)
        cout << opadajuci[i] << " ";
    return 0;
}