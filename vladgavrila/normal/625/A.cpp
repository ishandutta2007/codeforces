#include <iostream>

using namespace std;

long long n, a, b, c;

int main()
{
    cin>>n>>a>>b>>c;

    if(a <= (b-c))
    {
        cout<<n/a<<"\n";
        return 0;
    }

    long long fb = (n-b)/(b-c)+1;

    if(n<b)
        fb = 0;

    n -= fb * (b-c);
    cout<<n/a+fb<<"\n";

    return 0;
}