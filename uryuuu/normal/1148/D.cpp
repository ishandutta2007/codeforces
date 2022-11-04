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
#include <functional>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 11000
using namespace std;
int aa[1500010],bb[1500010];
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int s=0;
struct node
{
    int x,y,id;
}a[300005],b[300005];
bool cmp(node a,node b)
{
    return a.y>b.y;
}
bool cmp1(node a,node b)
{
    return a.y<b.y;
}
int main()
{
    int n;
    cin>>n;
    int aa=0,bb=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x<y)
        {
            a[aa].x=x;
            a[aa].y=y;
            a[aa].id=i;
            aa++;
        }
        if(x>y)
        {
            b[bb].x=x;
            b[bb].y=y;
            b[bb].id=i;
            bb++;
        }
    }
    if(aa>bb)
    {
        sort(a,a+aa,cmp);
        cout<<aa<<endl;
        for(int i=0;i<aa;i++)
        {
            cout<<a[i].id<<' ';
        }
    }
    else
    {
        sort(b,b+bb,cmp1);
        cout<<bb<<endl;
        for(int i=0;i<bb;i++)
        {
            cout<<b[i].id<<' ';
        }
    }
    return 0;
}