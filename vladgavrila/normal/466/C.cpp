#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

#define maxn 500010

int n, m, x;
long long v[maxn], sol;
multiset<long long> g;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(int i=1; i<n; ++i)
        if(v[i]*3==v[n]*2)
            ++x;


    for(int i=1; i<n; ++i)
    {
        if(v[i]*3==v[n]*2)
            --x;
        if(v[i]*3==v[n])
            sol+=x;
    }

    cout<<sol<<"\n";

    return 0;
}