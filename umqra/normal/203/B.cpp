#include <iostream>
using namespace std;
bool mas[2000][2000];
bool is_square ( int a, int b )
{
    for ( int i = a; i < a + 3; i++ )
    {
        for ( int s = b; s < b + 3; s++ )
        {
            if ( !mas[i][s] )
                return false;
        }
    }
    return true;
}
bool check ( int a, int b )
{                                                                      
    for ( int i = 0; i < 3; i++ )
    {
        for ( int s = 0; s < 3; s++ )
        {
            if ( is_square(a, b - s) || is_square(a + i, b - s) || is_square(a + i, b) || is_square(a - i, b) || is_square(a - i, b - s) )
                return true;
        }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for ( int i = 0; i < k; i++ )
    {
        int a, b;
        cin >> a >> b;  
        mas[a + 10][b + 10] = 1;
        if ( check(a + 10, b + 10) )
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}