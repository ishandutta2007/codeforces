#include <iostream>
using namespace std;
int mas[2000];
int main()
{
    int rez=0;
    int n;
    cin >> n;
    for ( int i=0; i<n; i++ )
        cin >> mas[i];
    for ( int i=1; i<n; i++ )
    {
        int t=0;
        bool h=false, f=false;
        for ( int s=0; s<i; s++ )
        {
            if ( mas[s]<mas[i] )
               h=true;
            if ( mas[s]>mas[i] )
               f=true;
            if ( mas[s]==mas[i] )
            {
               t=1;
               break;
            }
            if ( h&&f )
            {
                 t=1;
                 break;
            }
        }
        if ( !t )
           rez++;
    }
    cout << rez;
    cin >> n;
    return 0;
}