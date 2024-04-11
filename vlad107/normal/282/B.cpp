#include <iostream>
#include <cmath>


int a[1000001],g[1000001];
using namespace std;

int main()
{
    long long n,i,j,c,d; string s;
    cin>>n;
    c=0;
    d=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>g[i];
        if(fabs(c+a[i]-d)<=500)
        {
            c=c+a[i];
            s+='A';
        }
        else
        {
            d=d+g[i];
            s+='G';
        }
    }

 cout<<s;

return 0;
}