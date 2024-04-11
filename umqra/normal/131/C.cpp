#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
long long table[31][31];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    long long rez=0;
    for ( int i=1; i<=30; i++ )
    {
        for ( int s=1; s<=30; s++ )
        {
            if ( i==1 )
                table[i][s]=s;
            else if ( i<=s )
            {
                table[i][s]=table[i][s-1]+table[i-1][s-1];
            }
        }
    }
    for ( int i=1; i<=t-4; i++ )
    {
        int d=i, p=t-i;
        if ( d>0&&p>3&&d<=m&&p<=n )
        {
            long long dd=table[d][m];
            long long pp=table[p][n];
            //cout << dd << ' ' << pp << '\n';
            rez+=dd*pp;
        }
    }
    cout << rez;
    return 0;
}