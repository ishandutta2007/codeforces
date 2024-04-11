#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i",&t);
    for(int i=0;i<t;i++)
    {
        long long n,l,r;
        scanf("%lli%lli%lli",&n,&l,&r);
        printf((n/l*r>=n)?"Yes\n":"No\n");
    }
}