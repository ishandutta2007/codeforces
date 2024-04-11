#include<bits/stdc++.h>
using namespace std;
bool used[1005];
int a[55],b[55];
int main()
{
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    int s=1;
    for(int i=m;i>=1;i--)
    {
        if(used[a[i]]==false)
        {
            used[a[i]]=true;
            b[s++]=a[i];
        }
    }
    cout<<s-1<<endl;
    for(int i=s-1;i>=1;i--)
    {
        printf("%d ",b[i]);
    }
    return 0;
}