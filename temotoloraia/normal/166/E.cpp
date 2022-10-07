#include <iostream>
using namespace std;
long long a,b,c,n,m;
int main()
{
    cin>>n;
    a=1;b=0;
    while(n--)
    {
        c=(3*a+2*b)%1000000007;
        a=b;
        b=c;
    }
    cout<<a<<endl;
}