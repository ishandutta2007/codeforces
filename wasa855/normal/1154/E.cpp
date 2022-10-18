#include<bits/stdc++.h>
using namespace std;
int a[200005];
int l[200005];
int r[200005];
bool used[200005];
int t[200005];
priority_queue<int> q;
int ans[200005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        l[i]=i-1;
        r[i]=i+1;
        t[a[i]]=i;
        q.push(a[i]);
    }
    l[1]=0;
    r[n]=0;
    int res=1;
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        int pl=t[x];
        if(ans[pl]!=0)
        {
            continue;
        }
        int i=k;
        int left=pl;
        ans[pl]=res;
        while(i--)
        {
            left=l[left];
            if(left==0)
            {
                break;
            }
            ans[left]=res;
        }
        i=k;
        int right=pl;
        while(i--)
        {
            right=r[right];
            if(right==0)
            {
                break;
            }
            ans[right]=res;
        }
        int ll=l[left];
        int rr=r[right];
        if(ll!=0)
        {
            r[ll]=rr;
        }
        if(rr!=0)
        {
            l[rr]=ll;
        }
        if(res==1)
        {
            res=2;
        }
        else
        {
            res=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
    }
    return 0;
}