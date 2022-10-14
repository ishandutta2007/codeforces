#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    int f[m];
    int l[n];
    int matrica[n][m];
    for(int i = 0; i < m; i++)
        cin >> f[i];
    for(int i = 0; i < n; i++)
        cin >> l[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrica[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrica[i][j] == 1) matrica[i][j] = l[i];
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(matrica[i][j])
            {
                if(l[i] >= f[j]) matrica[i][j] = f[j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << matrica[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}