#include <iostream>
using namespace std;
int first[300000], second[300000];
int find_prefics ( int n )
{
    int cur = 0;
    int result = 0;
    for ( int i = 0; i < n; i++ )
    {
        while ( first[i] != second[cur] )
        {
            cur++;
            if ( cur == n )
                break;
        }
        if ( cur == n )
            break;
        result++;
    }
    return n - result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> first[i];
    for ( int s = 0; s < n; s++ )
        cin >> second[s];
    cout << find_prefics(n);
    return 0;
}