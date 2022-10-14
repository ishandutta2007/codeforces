#include <stdio.h>
#include <algorithm>
using namespace std;
long long n,avg,r,i,rez,sum;
pair <long long, long long> a[100500];
int main()
{
    scanf("%d%d%d",&n,&r,&avg);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d",&a[i].second,&a[i].first);
        sum += a[i].second;
    }
    sort(a,a+n);
    rez = i = 0;
    while (sum < avg*n)
    {
        long long tmp = min(avg*n-sum,r-a[i].second);
        rez += tmp*a[i].first;
        sum += tmp;
        i++;
    }
    printf("%I64d\n",rez);
    return 0;
}