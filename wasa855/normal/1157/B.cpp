#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[10];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%1d",&a[i]);
    }
    for(int i=1;i<=9;i++)
    {
        scanf("%1d",&b[i]);
    }
    int add=n+1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<b[a[i]])
        {
            add=i;
            break;
        }
    }
    for(int i=add;i<=n;i++)
    {
        if(a[i]<=b[a[i]])
        {
            a[i]=b[a[i]];
        }
        else break;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
///csadslijnheaiuhy