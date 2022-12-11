#include <iostream>
using namespace std;
int mas[1000];
int main()
{
    int n, ind_mi, ind_ma, mi=1000, ma=-1;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        cin >> mas[i];
        if ( mas[i]<=mi )
        {
             mi=mas[i];
             ind_mi=i;
        }
        if ( mas[i]>ma )
        {
             ma=mas[i];
             ind_ma=i;
        }
    }
    if ( ind_mi<ind_ma )
       cout << ind_ma+(n-ind_mi-2);
    else
       cout << ind_ma+(n-ind_mi-1);
    return 0;
}