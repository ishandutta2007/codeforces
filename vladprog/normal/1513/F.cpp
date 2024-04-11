#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=2e9;

int a[N],b[N];

struct asc_a
{
    bool operator()(int i,int j)const
    {
        if(a[i]!=a[j])
            return a[i]<a[j];
        return i<j;
    }
};

struct asc_b
{
    bool operator()(int i,int j)const
    {
        if(b[i]!=b[j])
            return b[i]<b[j];
        return i<j;
    }
};

struct des_a
{
    bool operator()(int i,int j)const
    {
        if(a[i]!=a[j])
            return a[i]>a[j];
        return i<j;
    }
};

struct des_b
{
    bool operator()(int i,int j)const
    {
        if(b[i]!=b[j])
            return b[i]>b[j];
        return i<j;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    vector<tuple<int,int,int>> ord;
    for(int i=1;i<=n;i++)
        ord.push_back({a[i],i,a[i]>b[i]?1:2}),
        ord.push_back({b[i],i,a[i]>b[i]?3:4});
    sort(ord.begin(),ord.end());
    set<int,asc_b> lef_min{n+1}; b[n+1]=INF;
    set<int,des_a> lef_max{n+2}; a[n+2]=-INF;
    set<int,asc_a> rig_min{n+3}; a[n+3]=INF;
    set<int,des_b> rig_max{n+4}; b[n+4]=-INF;
    int ans=0;
    for(auto[val,i,tp]:ord)
    {
        //cout<<"event i="<<i<<" tp="<<tp<<"\n";
        switch(tp)
        {
        case 1:
            ans=max(ans,a[i]-max(b[i],a[*rig_min.begin()]));
            lef_min.erase(i);
            lef_max.erase(i);
            break;
        case 2:
            ans=max(ans,min(b[i],a[*lef_max.begin()])-a[i]);
            rig_min.insert(i);
            rig_max.insert(i);
            break;
        case 3:
            ans=max(ans,min(a[i],b[*rig_max.begin()])-b[i]);
            lef_min.insert(i);
            lef_max.insert(i);
            break;
        case 4:
            ans=max(ans,b[i]-max(a[i],b[*lef_min.begin()]));
            rig_min.erase(i);
            rig_max.erase(i);
            break;
        }
    }
    int init=0;
    for(int i=1;i<=n;i++)
        init+=abs(a[i]-b[i]);
    //cout<<init<<" "<<ans<<" -> ";
    cout<<init-2*ans;
}