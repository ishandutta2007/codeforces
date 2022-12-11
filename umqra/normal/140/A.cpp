#include <iostream>
#include <cmath>
using namespace std;
const double pi=atan(1.)*4;;
int main()
{
    double n, R, r;
    cin >> n >> R >> r;
    if ( n==1 )
    {
       if ( r<=R )
          cout << "YES";
       else
           cout << "NO";    
    }
    else
    {
        double a=2*(R-r)*sin(pi/n);
        if ( a-2*r>=-0.00000001 )
           cout << "YES";
        else
            cout << "NO";
    }
    cin >> n;
    return 0;
}