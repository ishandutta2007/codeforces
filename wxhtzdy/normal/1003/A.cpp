#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back


    int ponavljanja[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int niz[n];
    for(int i = 0; i < n; i++)
    {
        cin >> niz[i];
        ponavljanja[niz[i]]++;
    }
    int rez = 0;
    for(int i = 0; i < 101; i++)
    {
        rez = max(rez, ponavljanja[i]);
    }
    cout << rez;
    return 0;
}