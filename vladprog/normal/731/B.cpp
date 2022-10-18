#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int k=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        t-=k;
        if(t<0)
            return printf("NO"),0;
        k=t%2;
    }
    if(k!=0)
        printf("NO");
    else
        printf("YES");
}