#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=500005;
const ll Mod=1e9+7;

struct node
{
    int l,r;
}s[maxn];

bool cmp(node a,node b)
{
    return a.l<b.l;
}
 
int a[maxn<<1],fa[maxn<<1];


int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}


map<int,int>mp;
int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].l>>s[i].r;
        a[s[i].l]=i;
        fa[i]=i;
    }
    sort(s+1,s+n+1,cmp);
//    cout<<findx(2)<<' '<<findx(3)<<endl;
    for(int i=1;i<=n;i++)
    {
        auto it=mp.lower_bound(s[i].l);
        while(it!=mp.end()&&(it->first)<s[i].r)
        {
            int u=findx(a[s[i].l]),v=findx(a[it->second]);
//            cout<<i<<' '<<u<<' '<<v<<endl;
            if(u==v)
            {
//                cout<<a[s[i].l]<<' '<<a[it->second]<<' ';
//                cout<<i<<' '<<u<<' '<<v<<' ';
                cout<<"NO"<<endl;
                return 0;
            }
            fa[u]=v;
            it++;
        }
        mp[s[i].r]=s[i].l;
    }
    int d=findx(1);
//    cout<<d<<' ';
    for(int i=2;i<=n;i++)
    {
//        cout<<findx(i)<<' ';
        if(findx(i)!=d)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}