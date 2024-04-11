#include<bits/stdc++.h>
using namespace std;
int main()
{
    double m,n,a;
    cin>>m>>n>>a;
    double aa,bb;
    aa=ceil(m/a);
    bb=ceil(n/a);
    long long ans=aa*bb;
    printf("%lld",ans);
    return 0;
}