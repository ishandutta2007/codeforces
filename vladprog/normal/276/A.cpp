#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int f,t;
        scanf("%d%d",&f,&t);
        m=max(m,(t<=k)?f:(f-t+k));
    }
    printf("%d",m);
}