#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
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
const ll Mod=1e9+7;
int a[200005];
struct node
{
    int p,s;
}b[200005],c[200005];
bool cmp(node a,node b)
{
    if(a.s==b.s)
        return a.p>b.p;
    return a.s>b.s;
}
int main()
{
    int t,x,y;
    cin>>t;
    int n,m;
    while(t--)
    {
        scanf("%d",&n);
        int d=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            d=max(d,a[i]);
        }
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&b[i].p,&b[i].s);
        }
        sort(b+1,b+m+1,cmp);
        int cnt=0;
        int da=0;
        for(int i=1;i<=m;i++)
        {
            if(da<b[i].p)
            {
                c[cnt].p=b[i].p;
                c[cnt++].s=b[i].s;
                da=b[i].p;
            }
        }
//        for(int i=0;i<cnt;i++)
//        {
//            cout<<c[i].p<<' '<<c[i].s<<endl;
//        }
        if(d>da)
        {
            cout<<-1<<endl;
            continue;
        }
        int nn=1;
        int e=0,j=cnt-1,sum=0;
        int dd=0;
        while(nn<=n)
        {
            e=0;
            j=cnt-1;
            sum++;
            dd=0;
            while(j>=0&&nn<=n)
            {
//                cout<<"H"<<endl;
                dd=max(a[nn],dd);
                if(c[j].p<dd)
                {
//                    cout<<c[j].p;
                    e=0;
                    j=cnt-1;
                    break;
                }
                while(c[j].p>=dd&&c[j].s>e&&nn<=n)
                {
                    e++;
                    nn++;
                    dd=max(a[nn],dd);
//                    cout<<sum<<' '<<c[j].p<<' '<<endl;
                }
                j--;
            }
//            cout<<nn<<endl;
//            cout<<"HH"<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}