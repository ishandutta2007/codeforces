#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e18;

pii aca[N],bcb[N];
pair<pii,int> xyz[N];

int t[4*N],p[4*N];

void build(int v,int tl,int tr)
{
    p[v]=0;
    if(tl==tr)
//        cout<<"t["<<tl<<"]="<<-bcb[tl].y<<"\n",
        t[v]=-bcb[tl].y;
    else
    {
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=max(t[v*2],t[v*2+1]);
    }
}

void push(int v,int tl,int tr)
{
    if(!p[v])
        return;
    t[v]+=p[v];
    if(tl!=tr)
        p[v*2]+=p[v],
        p[v*2+1]+=p[v];
    p[v]=0;
}

int get(int v,int tl,int tr,int l,int r)
{
    push(v,tl,tr);
    if(l<=tl&&tr<=r)
        return t[v];
    int tm=(tl+tr)/2;
    return max((l<=tm?get(v*2,tl,tm,l,r):-INF),
               (r>=tm+1?get(v*2+1,tm+1,tr,l,r):-INF));
}

void upd(int v,int tl,int tr,int l,int r,int val)
{
    if(l<=tl&&tr<=r)
    {
        p[v]+=val;
        push(v,tl,tr);
        return;
    }
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    if(l<=tm)
        upd(v*2,tl,tm,l,r,val);
    else
        push(v*2,tl,tm);
    if(r>=tm+1)
        upd(v*2+1,tm+1,tr,l,r,val);
    else
        push(v*2+1,tm+1,tr);
    t[v]=max(t[v*2],t[v*2+1]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
        cin>>aca[i].x>>aca[i].y;
    sort(aca+1,aca+n+1);
    for(int i=1;i<=m;i++)
        cin>>bcb[i].x>>bcb[i].y;
    sort(bcb+1,bcb+m+1);
    for(int i=1;i<=p;i++)
        cin>>xyz[i].x.x>>xyz[i].x.y>>xyz[i].y,
        xyz[i].x.x++,xyz[i].x.y++;
    sort(xyz+1,xyz+p+1);

//    int brute=-INF;
//    {
//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//            {
//                int res=-aca[i].y-bcb[j].y;
//                for(int q=1;q<=p;q++)
//                    if(xyz[q].x.x<=aca[i].x&&
//                       xyz[q].x.y<=bcb[j].x)
//                        res+=xyz[q].y;
//                brute=max(brute,res);
//            }
//        cout<<"BRUTE: "<<brute<<"\n";
//    }

    build(1,1,m);
    int ans=-INF;
    for(int i=1,j=1;i<=n;i++)
    {
        for(;j<=p&&xyz[j].x.x<=aca[i].x;j++)
        {
            int l=lower_bound(bcb+1,bcb+m+1,pii(xyz[j].x.y,0ll))-bcb;
            int r=m;
            int val=xyz[j].y;
            if(l<=r)
//                cout<<"upd(1,1,"<<m<<","<<l<<","<<r<<","<<val<<")\n";
                upd(1,1,m,l,r,val);
        }
        int res=get(1,1,m,1,m);
//        cout<<"get(1,1,"<<m<<",1,"<<m<<")="<<res<<"\n";
        ans=max(ans,-aca[i].y+res);
    }
    cout<<ans<<"\n";

//    if(ans==brute)
//        cout<<"OK\n";
//    else
//        cout<<"WA\n";
}