#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int t[4*N],p[4*N];

void build(int v,int tl,int tr)
{
    p[v]=-1;
    if(tl==tr)
        t[v]=1;
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
    t[v]=(tr-tl+1)*p[v];
    if(tl!=tr)
        p[v*2]=p[v*2+1]=p[v];
    p[v]=-1;
}

int get(int v,int tl,int tr,int l,int r)
{
    push(v,tl,tr);
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    if(r<=tm)
        return get(v*2,tl,tm,l,r);
    if(l>=tm+1)
        return get(v*2+1,tm+1,tr,l,r);
    return get(v*2,tl,tm,l,tm)+get(v*2+1,tm+1,tr,tm+1,r);
}

void upd(int v,int tl,int tr,int l,int r,int val=0)
{
    if(l==tl&&r==tr)
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
    else if(l>=tm+1)
        push(v*2,tl,tm),
        upd(v*2+1,tm+1,tr,l,r,val);
    else
        upd(v*2,tl,tm,l,tm,val),
        upd(v*2+1,tm+1,tr,tm+1,r,val);
    t[v]=t[v*2]+t[v*2+1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        int n=a.size();
        set<int> s[26];
        set<pii> m;
        for(int i=0;i<n-1;i++)
            if(a[i]==a[i+1])
                s[a[i]-'a'].insert(i),
                m.insert({i,a[i]-'a'});
        build(1,0,n-1);
        vector<pii> ans;
        while(true)
        {
            pii mx(0,-1);
            for(int i=0;i<26;i++)
                mx=max(mx,{s[i].size(),i});
            if(!mx.x)
                break;
            int pos=-1;
            for(int i=0;i<26;i++)
                if(i!=mx.y&&!s[i].empty())
                    pos=*s[i].begin();
            if(pos==-1)
                break;
            int pos_mx;
            bool forw=true;
            {
                auto it=s[mx.y].upper_bound(pos);
                if(it==s[mx.y].end())
                    it=prev(s[mx.y].lower_bound(pos)),
                    forw=false;
                pos_mx=*it;
            }
            int oth,pos_oth;
            {
                auto it=m.upper_bound({pos_mx,100ll});
                if(forw)
                    it=prev(m.lower_bound({pos_mx,0ll}));
                pos_oth=it->x;
                oth=it->y;
            }
            int l=pos_mx,r=pos_oth;
            if(l>r)
                swap(l,r);
            ans.push_back({get(1,0,n-1,0,l+1),get(1,0,n-1,0,r)});
            upd(1,0,n-1,l+1,r);
            s[mx.y].erase(pos_mx);
            s[oth].erase(pos_oth);
            m.erase({pos_mx,mx.y});
            m.erase({pos_oth,oth});
        }
        while(!m.empty())
        {
            int pos=m.begin()->x;
            m.erase(m.begin());
            ans.push_back({1,get(1,0,n-1,0,pos)});
            upd(1,0,n-1,0,pos);
        }
        ans.push_back({1,get(1,0,n-1,0,n-1)});
        cout<<ans.size()<<"\n";
        for(pii p:ans)
            cout<<p.x<<" "<<p.y<<"\n";
    }
}