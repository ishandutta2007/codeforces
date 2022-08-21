#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
    int x,y,z;
    int rp=1000000007;
int fuck(int z)
{
    switch(z%6)
    {
        case 0: return x;
        case 1: return y;
        case 2: return y-x;
        case 3: return -x;
        case 4: return -y;
        case 5: return x-y;
    }
}
int main()
{
    cin>>x>>y>>z;
    x%=rp; y%=rp;
    int sb=fuck(z-1);
    sb=(sb%rp+rp)%rp;
    cout<<sb;
}