#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long t, w, b;

long long cmmdc(long long a, long long b)
{
    long long r=a%b;
    while(r>0)
    {
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}

int main()
{
    cin>>t>>w>>b;

    if(w>b)
        swap(w, b);

    long long c=cmmdc(w, b);
    long long prop=b/c;
    long long s = t/w;
    long long sol=0;

    sol=(s/prop+1) * w - 1;

     //   cout<<sol<<"\n";

    if(s%prop==0)
    {
        long long tp=(s+1)*w-1;
        if(t<=tp)
            sol=sol-(tp-t);
    }

  //  cout<<sol<<"\n";

    long long kk=cmmdc(sol, t);

    cout<<sol/kk<<"/"<<t/kk<<"\n";

    return 0;
}