#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;

int arr[maxn];
void solve()
{
    int n;scanf("%d",&n);
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
        if(i>=2&&arr[i]!=arr[i-1])f=0;
    }
    if(f)
    {
        puts("1");
        for(int i=0;i<n;i++)printf("1 ");
        return;
    }
    else if(n%2==0)
    {
        puts("2");
        for(int i=0;i<n;i++)printf("%d ",i%2+1);
        return;
    }
    else if(arr[1]==arr[n])
    {
        puts("2");
        for(int i=0;i<n-1;i++)printf("%d ",i%2+1);
        printf("1");
        return;
    }

    for(int i=2;i<=n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            puts("2");
            for(int j=1;j<i-1;j++)printf("%d ",j%2+1);
            printf("%d %d ",2-i%2,2-i%2);
            for(int j=i+1;j<=n;j++)printf("%d ",2-j%2);
            return;
        }
    }
    puts("3");
    printf("3 ");
    for(int i=1;i<n;i++)printf("%d ",i%2+1);
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
        puts("");
    }
}