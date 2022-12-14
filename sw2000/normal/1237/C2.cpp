#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

struct A
{
    double x,y,z;
    int id;
}a[maxn];

bool cmp(A u,A v)
{
    if(u.x!=v.x)return u.x<v.x;
    if(u.y!=v.y)return u.y<v.y;
    return u.z<v.z;
}

bool vis[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);

    for(int i=0;i<n;i++)
    {
        if(vis[i])continue;
        int j=i+1,id;
        double mi=99999999999999999999999999999;
        while(vis[j])j++;
        if(a[i].x==a[j].x&&a[i].y==a[j].y)
        {
            id=j;
        }
        else if(a[i].x==a[j].x)
        {
            for(int k=j;a[k].x==a[j].x&&a[j].y==a[k].y;k++)
            {
                if(vis[k])continue;
                double dis=(a[i].z-a[k].z)*(a[i].z-a[k].z);
                if(dis<mi)
                {
                    id=k;
                    mi=dis;
                }
            }
        }
        else
        {
            for(int k=j;a[k].x==a[j].x;k++)
            {
                if(vis[k])continue;
                double dis=(a[i].y-a[k].y)*(a[i].y-a[k].y)+(a[i].z-a[k].z)*(a[i].z-a[k].z);
                if(dis<mi)
                {
                    id=k;
                    mi=dis;
                }
            }
        }

        vis[id]=1;
        printf("%d %d\n",a[i].id,a[id].id);
    }
    return 0;
}