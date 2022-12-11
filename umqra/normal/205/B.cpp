#include <iostream>
using namespace std;
long long mas[1000000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    long long pl = 0;
    for ( int i = 0; i < n; i++ )
        cin >> mas[i];
    for ( int i = 1; i < n; i++ )
    {
        if ( mas[i] + pl < mas[i - 1] )
        {
            long long t = mas[i - 1] - (mas[i] + pl);
            mas[i] = mas[i - 1];
            pl += t;
        }
        else
            mas[i] += pl;
        //cout << pl << ":" << mas[i] << endl;
    }
    cout << pl;
    return 0;
}