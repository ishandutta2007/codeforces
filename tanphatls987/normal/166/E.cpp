#include <iostream>
#include <string.h>
using namespace std;
const long int module=1000000007;
int main()
{
    int64_t a,b,tmp,n,i;
    cin>>n;
    a=1;b=0;
    for(i=1;i<n;i++)
    {
        tmp=b;
        b=(3*a)%module;
        a=(2*a+tmp)%module;
    }
    cout<<b;
}