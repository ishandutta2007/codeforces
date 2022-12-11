#include <iostream>
using namespace std;
int mas[1000];
int main()
{
    int n, k, count=0;
    cin >> n >> k;
    for ( int i=0; i<n; i++ )
        cin >> mas[i];
    for ( int i=0; i<n; i++ )
    {
        if ( mas[i]>=mas[k-1]&&mas[i]>0 )
           count++;
    }
    cout << count;
    cin >> n;
    return 0;
}