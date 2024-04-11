#include <iostream>

using namespace std;

int n, a;

int main()
{
    cin>>n>>a;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(a<=n/2)
        cout<<a+1;
    else
        cout<<a-1;

    return 0;
}