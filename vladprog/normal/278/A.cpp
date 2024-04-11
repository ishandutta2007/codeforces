#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],sum=0;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    int s,t;
    scanf("%d%d",&s,&t);
    s--;
    t--;
    if(s>t)swap(s,t);
    int dist=0;
    for(int i=s;i<t;i++)
        dist+=a[i];
    printf("%d",min(dist,sum-dist));
}