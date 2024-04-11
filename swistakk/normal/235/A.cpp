#include <iostream>
#include <algorithm>
#define uint long long int
using namespace std;
uint nwd(uint a, uint b)
{
    if(b>a)
    {
        swap(a, b);
    }
    if(b==0)
    return a;
    return nwd(b, a%b);
}
uint lcm(uint a, uint b)
{
    return (a/nwd(a, b))*b;
}
int main()
{
    uint n;
    cin>>n;
    if(n<=30)
    {
        uint maxi=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int k=1; k<=n; k++)
                {
                    maxi=max(maxi, lcm(i, lcm(j, k)));
                }
            }
        }
        cout<<maxi<<endl;
    }
    else
    {
        if(n%2==0)
        {
            if(n%3!=0)
            {
                cout<<n*(n-1)*(n-3)<<endl;
                return 0;
            }
        
            n--;
        }
        cout<<n*(n-1)*(n-2)<<endl;
    }
    return 0;
}