#include <stdio.h>
#include <iostream>

using namespace std;

#define maxn 510

int n, mx, my;
long long v[maxn][maxn];

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            cin>>v[i][j];
            if(v[i][j]==0)
            {
                mx=i;
                my=j;
            }
        }

    if(n==1)
    {
        printf("1\n");
        return 0;
    }

    int gl=1;
    if(mx==1)
        gl=0;

    long long sol=0, tsum=0;

    for(int i=0; i<n; ++i)
        sol+=v[gl][i];

    tsum=sol;

    for(int i=0; i<n; ++i)
        sol-=v[mx][i];


    if(sol<=0)
    {
        printf("-1\n");
        return 0;
    }

    v[mx][my]=sol;

    for(int i=0; i<n; ++i)
    {
        long long sum=0;
        for(int j=0; j<n; ++j)
            sum+=v[i][j];
        if(sum!=tsum)
        {
            printf("-1\n");
            return 0;
        }
    }

    for(int i=0; i<n; ++i)
    {
        long long sum=0;
        for(int j=0; j<n; ++j)
            sum+=v[j][i];
        if(sum!=tsum)
        {
            printf("-1\n");
            return 0;
        }
    }

    {
        long long sum=0;
        for(int j=0; j<n; ++j)
            sum+=v[j][j];
        if(sum!=tsum)
        {
            printf("-1\n");
            return 0;
        }
    }

    {
        long long sum=0;
        for(int j=0; j<n; ++j)
            sum+=v[n-j-1][j];
        if(sum!=tsum)
        {
            printf("-1\n");
            return 0;
        }
    }

    cout<<sol<<"\n";
    return 0;
}