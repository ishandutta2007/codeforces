#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int week[10];
int main()
{
    int n;
    cin >> n;
    for ( int i=0; i<7; i++ )
        cin >> week[i];
    while ( true )
    {
        for ( int i=0; i<7; i++ )
        {
            n-=week[i];
            if ( n<=0 )
            {
                cout << i+1;
                return 0;
            }
        }
    }
    return 0;
}