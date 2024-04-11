#include<bits/stdc++.h>
using namespace std;
int n;
struct Node
{
    int dat;
    int pl;
};
Node a[200005];
bool cmp(Node x,Node y)
{
    if(x.dat==y.dat)
    {
        return x.pl<y.pl;
    }
    return x.dat<y.dat;
}
int t[200005];
int ans[200005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x)
{
    while(x<=n)
    {
        t[x]++;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].dat);
        a[i].pl=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        add(a[i].pl);
        for(int j=1;j<n&&a[i].pl*j-j+2<=n;j++)
        {
            ans[j]+=query(min(a[i].pl*j+1,n))-query(a[i].pl*j-j+1);
        }
    }
    for(int i=1;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    cout<<"\n";
    return 0;
}