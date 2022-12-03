#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long gcd(long long x,long long y)
{
    if (y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for (i=0;i<n;i++)
    {
        long long p,q,b;
        cin>>p>>q>>b;
        q/=gcd(p,q);
        long long k=b;
        for (;;)
        {
            k=gcd(q,k);
            if ((k==1)&&(q==1))
            {
                puts("Finite");
                break;
            }
            if (k==1)
            {
                puts("Infinite");
                break;
            }
            q/=k;
        }
    }
    return 0;
}