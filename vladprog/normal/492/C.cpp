#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long r,s;
    scanf("%d%I64d%I64d",&n,&r,&s);
    s*=n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].second,&a[i].first),
        s-=a[i].second;
    if(s<=0)
        printf("0"),
        exit(0);
    sort(a,a+n);
    long long t=0;
    for(int i=0;i<n;i++)
        if(s>r-a[i].second)
            s-=r-a[i].second,
            t+=(r-a[i].second)*a[i].first;
        else
            t+=s*a[i].first,
            printf("%I64d",t),
            exit(0);
}