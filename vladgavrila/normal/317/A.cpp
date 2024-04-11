#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define maxn 100010

long long sol, n, m, a, b, x;

int main()
{
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);

    cin>>a>>b>>m;
    if(a>b)
        swap(a, b);

    if(b>=m)
    {
        printf("0\n");
        return 0;
    }
    if(b<=0)
    {
        printf("-1\n");
        return 0;
    }

    if(a<=0)
    {
        x=(-a)/b;
        sol=x;
        a+=sol*b;
    }

    while(b<m)
    {
        ++sol;
        a+=b;
        if(a>b)
            swap(a, b);
    }

    cout<<sol<<"\n";


    return 0;
}