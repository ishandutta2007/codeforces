#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long int n,m,a,ans;
    cin>>n>>m;
    ans=0;
    for(a=0;a<=sqrt(n);a++)
    {
        if (((n-a*a)*(n-a*a))==(m-a)) ans++;
    }
    cout<<ans;
}