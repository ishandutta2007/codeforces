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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2005;

struct node
{
    int x,y,z,id;
}a[maxn];

bool cmp(node a,node b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
            return a.z<b.z;
        else
            return a.y<b.y;
    }
    return a.x<b.x;
}
int v[2005];
int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);
    int xx,xy,xz,dx,dy,dz;
    mm(v);
    xx=dx=a[0].x;
    xy=dy=a[0].y;
    xz=dy=a[0].z;
    int f=0;
    int id;
//    for(int i=0;i<n;i++)
//        cout<<a[i].id<<' ';
//    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(v[i])
            continue;
        xx=dx=-1;
        xy=dy=-1;
        xz=dz=-1;
        for(int j=i+1;j<n;j++)
        {
            if(v[j])
                continue;
            if(f==0)
            {
                xx=min(a[i].x,a[j].x);
                xy=min(a[i].y,a[j].y);
                xz=min(a[i].z,a[j].z);
                dx=max(a[i].x,a[j].x);
                dy=max(a[i].y,a[j].y);
                dz=max(a[i].z,a[j].z);
                id=j;
//                cout<<endl<<a[j].id<<endl;
                f=1;
            }
            else
            {
                if(a[j].x>=xx&&a[j].x<=dx&&a[j].y>=xy&&a[j].y<=dy&&a[j].z>=xz&&a[j].z<=dz)
                {
                    xx=min(a[i].x,a[j].x);
                    xy=min(a[i].y,a[j].y);
                    xz=min(a[i].z,a[j].z);
                    dx=max(a[i].x,a[j].x);
                    dy=max(a[i].y,a[j].y);
                    dz=max(a[i].z,a[j].z);
                    id=j;
//                    cout<<"sdfdf"<<a[j].id<<endl;
                }
            }
        }
        cout<<a[i].id<<' '<<a[id].id<<endl;
        v[i]=1;
        v[id]=1;
        f=0;
    }
    
    return 0;
}