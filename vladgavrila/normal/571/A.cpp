
#include <iostream>

using namespace std;

int a, b, c, l;

long long calc(int big, int small)
{
    long long sol = 0;
    int pls;

    for(int i=0; i<=l; ++i)
    {
        pls=min(l-i, (big+i)-small);

        if(pls<0)
            continue;
        sol = sol + (1LL*pls+2)*(pls+1)/2;
    }

    return sol;
}




int main()
{
    cin>>a>>b>>c>>l;

    long long deg = calc(a, b+c) + calc(b, a+c) + calc(c, a+b);
    long long tot = (1LL*l+3)*(l+2)*(l+1)/6;

    cout<<tot-deg<<"\n";

    return 0;
}