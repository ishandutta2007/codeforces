#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

string f;
int t[4*N],p[4*N];

void build(int v,int tl,int tr)
{
    p[v]=-1;
    if(tl==tr)
        t[v]=f[tl]-'0';
    else
    {
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

void push(int v,int tl,int tr)
{
    if(p[v]==-1)
        return;
    t[v]=p[v]*(tr-tl+1);
    if(tl!=tr)
        p[v*2]=p[v*2+1]=p[v];
    p[v]=-1;
}

int get(int v,int tl,int tr,int l,int r)
{
    push(v,tl,tr);
    if(l<=tl&&tr<=r)
        return t[v];
    int tm=(tl+tr)/2;
    if(r<=tm)
        return get(v*2,tl,tm,l,r);
    if(l>tm)
        return get(v*2+1,tm+1,tr,l,r);
    return get(v*2,tl,tm,l,r)+
           get(v*2+1,tm+1,tr,l,r);
}

void upd(int v,int tl,int tr,int l,int r,int val)
{
    if(l<=tl&&tr<=r)
    {
        p[v]=val;
        push(v,tl,tr);
        return;
    }
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    if(r<=tm)
        upd(v*2,tl,tm,l,r,val),
        push(v*2+1,tm+1,tr);
    else if(l>tm)
        push(v*2,tl,tm),
        upd(v*2+1,tm+1,tr,l,r,val);
    else
        upd(v*2,tl,tm,l,r,val),
        upd(v*2+1,tm+1,tr,l,r,val);
    t[v]=t[v*2]+t[v*2+1];
}

int l[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s>>f;
        s="_"+s,f="_"+f;
        for(int i=1;i<=q;i++)
            cin>>l[i]>>r[i];
        build(1,1,n);
        bool yes=true;
        for(int i=q;i>=1;i--)
        {
            int len=r[i]-l[i]+1;
            int one=get(1,1,n,l[i],r[i]);
            int zero=len-one;
//            cout<<i<<" : "<<l[i]<<".."<<r[i]<<" -> "<<len<<" "<<one<<" "<<zero<<"\n";
            if(one<zero)
                upd(1,1,n,l[i],r[i],0);
            else if(zero<one)
                upd(1,1,n,l[i],r[i],1);
            else
            {
                yes=false;
                break;
            }
        }
        for(int i=1;i<=n;i++)
            if(s[i]!='0'+get(1,1,n,i,i))
            {
                yes=false;
                break;
            }
        cout<<(yes?"YES\n":"NO\n");
    }
}