#include <iostream>
using namespace std;
int mas[10000];
int main()
{
    int n, k=0, rez=0;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        cin >> mas[i];
        rez+=mas[i];
    }
    for ( int i=0; i<n; i++ )
    {
        if ( (rez-mas[i])%2==0 )
           k++;
    }
    cout << k;
    cin >>n;
    return 0;
}