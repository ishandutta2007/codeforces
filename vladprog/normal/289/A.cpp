#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        sum=(sum+r-l+1)%k;
    }
    printf("%d\n",(k-sum)%k);
}