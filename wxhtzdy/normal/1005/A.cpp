#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int niz[n];
    int brojac = 0;
    vector<int> stepenice;
    for(int i = 0; i < n; i++)
    {
        cin >> niz[i];
        if(niz[i] == 1)
        {
            brojac++;
            if(i > 0) stepenice.push_back(niz[i-1]);
        }
    }
    stepenice.push_back(niz[n-1]);
    cout << brojac << "\n";
    for(int i = 0; i < stepenice.size(); i++)
        cout << stepenice[i] << " ";
    return 0;
}