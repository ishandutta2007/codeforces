#include <iostream>
using namespace std;
int no ( int a )
{
    if ( a<0 )
        return 0;
    return a;
}
int main()
{
    double a;
    cin >> a;
    double duim=(int)(a/3.+0.5);
    double fut=(int)(duim/12.);
    cout << fut << ' ' << no(duim-(fut*12));
    return 0;
}