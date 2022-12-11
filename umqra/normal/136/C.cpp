#include <iostream>
#include <algorithm>
using namespace std;
long long mas[100001];
int main()
{
    long long n, in, ma=-1;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        cin >> mas[i];
        if ( mas[i]>ma )
        {
            ma=mas[i];
            in=i;
        }
    }
    if ( ma!=1 )
        mas[in]=1;
    else
        mas[in]=2;
    sort(mas, mas+n);
    for ( int i=0; i<n; i++ )
        cout << mas[i] << ' ';
    return 0;
}