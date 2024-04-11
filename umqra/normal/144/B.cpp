#include <iostream>
#include <cmath>
using namespace std;
struct teplo
{
       double x, y;
       double r;
};
teplo mas[2000];
int n;
bool check ( double x, double y )
{
     for ( int i=0; i<n; i++ )
     {
         double x1=mas[i].x;
         double y1=mas[i].y;
         double ras=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
         if ( ras<=mas[i].r )
            return true;
     }
     return false;
}
int main()
{
    int count=0;
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    cin >> n;
    for ( int i=0; i<n; i++ )
        cin >> mas[i].x >> mas[i].y >> mas[i].r;
    
    for ( double i=min(xa, xb); i<=max(xa, xb); i++ )
    {
        if ( !check(i, ya) )
           count++;
        if ( !check(i, yb) )
           count++;
    }
    for ( double i=min(ya, yb)+1; i<max(ya, yb); i++ )
    {
        if ( !check(xa, i) )
           count++;
        if ( !check(xb, i) )
           count++;
    }
    cout << count;
    cin >> n;
    return 0;
}