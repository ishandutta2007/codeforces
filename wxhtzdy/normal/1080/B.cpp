#include <bits/stdc++.h>

using namespace std;

int Sum(int n)
{
    if (n%2==0)return n/2;
    else return (n+1)/2*-1;
}
int main()
{
    int q;
    scanf("%i",&q);
    while(q--)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        printf("%i\n",Sum(r)-Sum(l-1));
    }
    return 0;
}