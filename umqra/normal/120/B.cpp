#include<iostream>
#include<string>
using namespace std;
int mas[10000];
int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    for ( int i=0; i<n; i++ )
        cin >> mas[i];
    for ( int i=k-1; i<n; i++ )
    {
        if ( mas[i]==1 )
        {
            cout << i+1;
            return 0;
        }
    }
    for ( int i=0; i<n; i++ )
    {
        if ( mas[i]==1 )
        {
            cout << i+1;
            return 0;
        }
    }
    return 0;
}