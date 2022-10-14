#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        int niz[n];
        int brojac1 = 0;
        int brojac2 = 0;
        int brojac3 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> niz[i];
            niz[i] = (niz[i]-1)%3+1;
            if(niz[i] == 1) brojac1++;
            else if(niz[i] == 2) brojac2++;
            else brojac3++;
        }
        cout << brojac3+min(brojac1, brojac2)+(max(brojac1, brojac2)-min(brojac1, brojac2))/3 << "\n";

    }
}