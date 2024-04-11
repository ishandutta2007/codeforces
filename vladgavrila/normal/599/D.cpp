#include <cstdio>
#include <iostream>

using namespace std;

#define maxn 2000010

long long n, m, nsol;
long long a[maxn], b[maxn];
int main()
{
    cin>>n;

    for(int i=1; true; ++i)
    {
        long long cr = (n*6/(i+1)/(i)+i-1)/3;
        if(cr<i)
            break;
        if(((1LL*i+1)*(i)*(3*cr+1-i))==n*6)
        {
            a[++nsol]=i;
            b[nsol]=cr;
        }
    }

    if(a[nsol]==b[nsol])
        cout<<2*nsol-1<<"\n";
    else
        cout<<2*nsol<<"\n";

    for(int i=1; i<=nsol; ++i)
        cout<<a[i]<<" "<<b[i]<<"\n";

    for(int i=nsol; i; --i)
        if(a[i]!=b[i])
            cout<<b[i]<<" "<<a[i]<<"\n";
    return 0;
}