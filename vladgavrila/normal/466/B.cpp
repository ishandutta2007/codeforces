#include <cstdio>
#include <iostream>

using namespace std;

long long n, a, b, am, bm, amin;

void incearcaA(int an)
{
    long long bn=max(b, 6*n/an);
    if(an*bn<6*n)
        ++bn;
    if(an*bn<=amin)
    {
        amin=an*bn;
        am=an;
        bm=bn;
    }
}

void incearcaB(int bn)
{
    long long an=max(a, 6*n/bn);
    if(an*bn<6*n)
        ++an;
    if(an*bn<=amin)
    {
        amin=an*bn;
        am=an;
        bm=bn;
    }
}

int main()
{
    cin>>n>>a>>b;
    amin=1LL*1000000000*1000000000;

    if(a*b>=6*n)
    {
        cout<<a*b<<"\n"<<a<<" "<<b<<"\n";
        return 0;
    }

    for(int i=0; i<=1000000; ++i)
    {
        incearcaB(b+i);
        incearcaA(a+i);
    }

    cout<<am*bm<<"\n"<<am<<" "<<bm<<"\n";

    return 0;
}