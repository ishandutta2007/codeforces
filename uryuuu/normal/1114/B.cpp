#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
int inf=0x3f3f3f3f;
using namespace std;
struct node
{
    int sz,id,mn,flag;
}a[200010];
bool cmp(node a,node b)
{
    if(a.mn==b.mn)
        return a.id<b.id;
    return a.mn>b.mn;
}
bool ccc(node a,node b)
{
    return a.id<b.id;
}
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        long long s=0;
        int t=0,tt=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].sz;
            a[i].mn=a[i].sz;
            a[i].id=i;
            a[i].flag=0;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<m*k;i++)
        {
            s+=a[i].mn;
            a[i].flag=1;
        }
        cout<<s<<endl;
        sort(a,a+n,ccc);
        for(int i=0;i<n;i++)
        {
            if(a[i].flag)
            {
                t++;
            }
            if(t==m)
            {
                tt++;
                t=0;
                if(tt==k)
                    break;
                cout<<i+1<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}