#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int mas[10000];
int main()
{
    int n, all = 0;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> mas[i];
        all += mas[i];
    }
    sort(mas, mas+n);
    int now = 0;
    int i;
    for ( i = n - 1; i>=0; i-- )
    {
        now += mas[i];
        if ( all - now < now )
           break;
    }
    cout << n - i;
    cin >> n;
    return 0;
}