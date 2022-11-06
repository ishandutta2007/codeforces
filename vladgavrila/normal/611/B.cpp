#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
long long sol, a, b;

int main()
{
    cin>>a>>b;

    long long st=1;

    for(int i=1; i<=62; ++i)
    {
        long long cr = st*2;
        for(int j=1; i+j<=63; ++j)
        {
            if(a<=cr && cr<=b)
                ++sol;
            cr=cr*2+1;
        }
        st=st*2+1;
    }

    cout<<sol<<"\n";

    return 0;
}