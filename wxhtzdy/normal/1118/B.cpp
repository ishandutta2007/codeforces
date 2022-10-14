#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int niz[n+1];
    int parni = 0, neparni = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> niz[i];
        if(i % 2 == 0) parni += niz[i];
        else neparni += niz[i];
    }
    int parnipom = 0, neparnipom = 0;
    int brojac = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0) parnipom += niz[i];
        else neparnipom += niz[i];                                                          //1 4 3 3
        if(i % 2 == 0)
        {
            if(parnipom-niz[i]+neparni-neparnipom == neparnipom+parni-parnipom) brojac++;
        }
              //
        else
            if(neparnipom-niz[i]+parni-parnipom == parnipom+neparni-neparnipom) brojac++;   //
    }
    cout << brojac << "\n";
}