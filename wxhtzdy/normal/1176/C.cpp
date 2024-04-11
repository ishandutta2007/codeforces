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
    int n;
    cin >> n;
    int niz[n];
    for(int i = 0; i < n; i++)
    {
        cin >> niz[i];
        if(niz[i] == 4) niz[i] = 0;
        else if(niz[i] == 8) niz[i] = 1;
        else if(niz[i] == 15) niz[i] = 2;
        else if(niz[i] == 16) niz[i] = 3;
        else if(niz[i] == 23) niz[i] = 4;
        else niz[i] = 5;
    }
    int rez = 0;
    for(int i = 0; i < n; i++)
    {
        if(niz[i] == 0) brojac[0]++;
        else
        {
            if(brojac[niz[i]-1] > 0)
            {
                brojac[niz[i]]++;
                brojac[niz[i]-1]--;
            }
            else rez++;
        }
    }
    for(int i = 0; i < 5; i++)
        rez += brojac[i]*(i+1);
    cout << rez;
}