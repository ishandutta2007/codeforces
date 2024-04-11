#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 200010

int n, m;
long long sum[maxn];
int v[maxn];

long long getSum(int a, int b)
{
    return sum[b]-sum[a-1];
}

double getAverage(int mpos, int lg)
{
    long long sum = getSum(mpos-lg, mpos) + getSum(n-lg+1, n);
    return double(sum) / (2*lg+1) - v[mpos];
}

double getAverage2(int mpos, int lg)
{
    long long sum = getSum(mpos-lg, mpos+1) + getSum(n-lg+1, n);
    return double(sum) / (2*lg+2) - double(v[mpos]+v[mpos+1])/2;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
    }


    sort(v+1, v+n+1);


    for(int i=1; i<=n; ++i)
    {
        sum[i]=sum[i-1]+v[i];
    }


    double solmax = getAverage(1, 0);
    int mpos=1, lg=0, par=0;

    for(int i=2; i<n; ++i)
    {
        int left=2;
        int right = min(n-i, i-1);
        int med, sol=1;
        while(left<=right)
        {
            int med=(left+right)/2;
            if(getAverage(i, med)>getAverage(i, med-1))
            {
                sol=med;
                left=med+1;
            }
            else
                right=med-1;
        }
        if(getAverage(i, sol)>solmax)
        {
            solmax=getAverage(i, sol);
            mpos=i;
            lg=sol;
        }
    }

    for(int i=2; i<n-1; ++i)
    {
        int left=2;
        int right = min(n-i-1, i-1);
        int med, sol=1;
        while(left<=right)
        {
            int med=(left+right)/2;
            if(getAverage2(i, med)>getAverage2(i, med-1))
            {
                sol=med;
                left=med+1;
            }
            else
                right=med-1;
        }
        if(getAverage2(i, sol)>solmax)
        {
            par=1;
            solmax=getAverage2(i, sol);
            mpos=i;
            lg=sol;
        }
    }

    printf("%d\n", 2*lg+1+par);
    for(int i=mpos-lg; i<=mpos; ++i)
        printf("%d ", v[i]);
    if(par)
        printf("%d ", v[mpos+1]);
    for(int i=n-lg+1; i<=n; ++i)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}