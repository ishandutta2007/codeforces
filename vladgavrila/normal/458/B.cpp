#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m, sol;
int a[maxn], b[maxn];
long long sum1, sum2, sol1, sol2;

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        sum1=sum1+a[i];
    }

    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &b[i]);
        sum2=sum2+b[i];
    }

    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    long long sol = 1LL*1000000000*1000000000;

    for(int i=1; i<n; ++i)
        if(a[i]<sum2)
            sol1=sol1+a[i];
        else
            sol1=sol1+sum2;
    sol1+=sum2;

    for(int i=1; i<m; ++i)
        if(b[i]<sum1)
            sol2=sol2+b[i];
        else
            sol2=sol2+sum1;
    sol2+=sum1;

    sol=min(sol, sol1);
    sol=min(sol, sol2);

    cout<<sol<<"\n";

    return 0;

}