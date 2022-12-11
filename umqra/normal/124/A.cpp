#include <iostream>
using namespace std;
int main()
{
    int n, a, b, otv=0;
    cin >> n >> a >> b;
    for ( int i=0; i<=b; i++ )
    {
        int a2=n-1-i;
        if ( a2>=a )
            otv++;
    }
    cout << otv;
    return 0;
}