#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int a[101];
    memset(a,0,sizeof(a));
    int l,r;
    scanf("%i%i",&l,&r);
    for(int i=1;i<n;i++)
    {
        int l,r;
        scanf("%i%i",&l,&r);
        a[l]++;
        a[r]--;
    }
    for(int i=1;i<=100;i++)
        a[i]+=a[i-1];
    int k=0;
    for(int i=l;i<r;i++)
        if(!a[i])
            k++;
    printf("%i",k);
}