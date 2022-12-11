#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
using namespace std;
long long p[100];   
long long res[10];
const long long INF = (int)1e16;
long long prize[10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> p[i];
    for ( int i = 0; i < 5; i++ )
        cin >> prize[i]; 
    long long cnt = 0;
    for ( int i = 0; i < n; i++ )
    {
        cnt += p[i];
        while ( 1 )
        {
            long long max_v, d = INF;
            for ( int s = 0; s < 5; s++ )
            {
                if ( prize[s] <= cnt && d > cnt - prize[s] )
                {
                    max_v = s;
                    d = cnt - prize[s];
                }
            }
            if ( d == INF )
                break;  
            res[max_v] += cnt / prize[max_v];
            cnt %= prize[max_v];
        }
    }
    for ( int i = 0; i < 5; i++ )
        cout << res[i] << ' ';  
    cout << endl << cnt;
    return 0;
}