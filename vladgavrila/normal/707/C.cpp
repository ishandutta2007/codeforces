#include <cstdio>
#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;

    if(n==1 || n==2)
    {
        cout<<"-1\n";
        return 0;
    }

    long long f;

    if(n%4==0)
    {
        f = n/4;
        cout<<3*f<<" "<<5*f<<"\n";
        return 0;
    }

    if(n%2==0)
    {
        f = 2;
        n/=2;
    }
    else
        f = 1;

    long long p = 1LL*n*n;

    cout<<p/2*f<<" "<<(p/2+1)*f<<"\n";

    return 0;
}