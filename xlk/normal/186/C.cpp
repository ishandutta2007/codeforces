#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define M 1000000007
using namespace std;
int n;
inline long long pw(long long x)
{
    long long res(1);
    long long k = 2;
    while(x)
    {
        if(x&1) res = ((long long)res*k)%M;
        x >>= 1;
        k = (k*k)%M;
    }
    return res;
}
int main()
{
    long long n;
    scanf("%I64d",&n);
    if(!n){puts("1");return 0;}
    long long tmp = pw(n-1);
    long long res = (tmp*2+1)*tmp%M;
    cout<<res<<endl;
}