#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int a[maxn];

int main()
{
    int n;
    bool flag1=0,flag2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]&1)flag1=1;
        else flag2=1;
    }
    if(flag1&&flag2)
    {
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(i)printf(" ");
            printf("%d",a[i]);
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(i)printf(" ");
            printf("%d",a[i]);
        }
    }


    return 0;
}