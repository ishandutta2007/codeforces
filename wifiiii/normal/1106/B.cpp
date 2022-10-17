#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

struct dish
{
    int id;
    ll a,c;
    bool operator < (const dish d) const
    {
        return c==d.c?id<d.id:c<d.c;
    }
};
dish ds[100005];
int idx[100005]; // idx[i] means the current pos of id_th dish,ds[idx[id]] is ok
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>ds[i].a;
    for(int i=1;i<=n;++i) cin>>ds[i].c;
    for(int i=1;i<=n;++i) ds[i].id = i;
    sort(ds+1,ds+1+n);
    for(int i=1;i<=n;++i) idx[ds[i].id] = i;
    int now = 1;
    while(m--)
    {
        ll t,d;
        cin>>t>>d;
        ll sum = 0;
        if(ds[idx[t]].a>=d) ds[idx[t]].a -= d, sum += ds[idx[t]].c * d;
        else
        {
            sum += ds[idx[t]].c * ds[idx[t]].a, d -= ds[idx[t]].a, ds[idx[t]].a = 0;
            while(now<=n)
            {
                if(ds[now].a>=d) {ds[now].a -= d, sum += ds[now].c * d;break;}
                else sum += ds[now].c * ds[now].a, d -= ds[now].a, ds[now].a = 0, now++;
            }
            if(now>=n+1) sum = 0;
        }
        cout << sum << endl;
    }
}