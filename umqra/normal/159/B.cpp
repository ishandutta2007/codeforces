#include <iostream>
using namespace std;
int table[2000][2000],table2[2000][2000]; 
int main()
{
    int u = 0, v = 0;
    int n, m;
    cin >> n >> m;
    for ( int i = 0; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        table[a][b]++;
    }
    for ( int i = 0; i < m; i++ )
    {
        int a, b;
        cin >> a >> b;
        table2[a][b]++;
    }
    for ( int i = 0; i < 2000; i++ )
    {
        int k = 0, f = 0;
        int b = 0;
        for ( int s = 0; s < 2000; s++ )
        {
            if ( table[s][i] ) 
               f += table[s][i];
            if ( table2[s][i] )
               k += table2[s][i];
            if ( table[s][i] && table2[s][i] )
               b += min(table[s][i], table2[s][i]);
        }
        u += min(f, k);
        v += b;
    }
    cout << u << ' ' << v;
    cin >> n;
    return 0;
}