#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 1000000
using namespace std;
int a[maxn+5];
int main()
{
    int n,i,v,ptr;
    scanf("%d",&n);
    ptr=n;
    rep(i,1,n)
    {
        int cnt=0;
        scanf("%d",&v),a[v]=1;
        while(a[ptr])
        {
            if(cnt) printf(" ");
            cnt++;
            printf("%d",ptr);
            ptr--;
        }
        printf("\n");
    }
    return 0;
}