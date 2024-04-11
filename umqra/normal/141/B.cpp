#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a;
    int x, y;
    cin >> a >> x >> y;
    int py=y/a+1;
    int ind=py+(py-1)/2;
    if ( y%(int)a==0 )
       cout << -1;
    else if ( py>2&&py%2==1 )
    {
         if ( x>-a&&x<0 )
            cout << ind-1;
         else if ( x>0&&x<a )
             cout << ind;
         else
             cout << -1;
    }
    else
    {
        if ( x>-a/2&&x<a/2 )
           cout << ind;
        else
            cout << -1;
    }
    cin >> a;
    return 0;
}