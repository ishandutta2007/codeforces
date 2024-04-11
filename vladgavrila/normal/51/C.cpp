#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 200010

int n, i, j, k, left, right, sol;
int v[maxn];
double poz[5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);
    sort(v+1, v+n+1);
    left=0;
    right=1000000010;
    while(left<=right)
    {
        int med=(1LL*left+right)/2;
        int p1=v[1]+med;
        int i;
        for(i=1; i<=n && v[i]<=p1; ++i);
        int p2=v[i]+med;
        for(; i<=n && v[i]<=p2; ++i);
        int p3=v[i]+med;
        if(v[n]<=p3 || i>n)
        {
            sol=med;
            poz[1]=p1-(double)med/2;
            poz[2]=p2-(double)med/2;
            poz[3]=p3-(double)med/2;
            right=med-1;
        }
        else
            left=med+1;
    }
    printf("%.6lf\n", (double)sol/2);
    printf("%.6lf %.6lf %.6lf\n", poz[1], poz[2], poz[3]);
    return 0;
}