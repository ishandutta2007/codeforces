//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=1e5+100;

int a[N];
vector<int> b[N];

int p[N];
set<int> s;
int cnt;

void start()
{
    cnt=0;
    s.clear();
}

void add(int x)
{
    cnt++;
    s.insert(x);
    p[x]=x;
}

int dsu(int x)
{
    return x==p[x]?x:p[x]=dsu(p[x]);
}

bool un(int x,int y)
{
    x=dsu(x);
    y=dsu(y);
    if(x==y)
        return false;
    if(rand()&1)
        p[x]=y;
    else
        p[y]=x;
    return cnt--, true;
}

int c[N];

int solve(int l,int r)
{
    if(l==r)
    {
        start();
        for(int x:b[l])
        {
            add(x);
            if(s.count(x-1))
                un(x,x-1);
            if(s.count(x+1))
                un(x,x+1);
        }
//        cout<<l<<" .. "<<r<<" -> "<<cnt<<"\n";
        return cnt;
    }
    if(l>r)
        return 0;
    int m=(l+r)/2;
    map<int,int> mp;
    start();
    for(int i=m;i>=l;i--)
    {
        for(int x:b[i])
        {
            add(x);
            if(s.count(x-1))
                un(x,x-1);
            if(s.count(x+1))
                un(x,x+1);
        }
        c[i]=cnt;
    }
    for(int x:s)
        mp[x]=1;
    start();
    for(int i=m+1;i<=r;i++)
    {
        for(int x:b[i])
        {
            add(x);
            if(s.count(x-1))
                un(x,x-1);
            if(s.count(x+1))
                un(x,x+1);
        }
        c[i]=cnt;
    }
    for(int x:s)
        mp[x]=2;
    start();
    for(int i=m;i<=m+1;i++)
        for(int x:b[i])
        {
            add(x);
            if(s.count(x-1))
                un(x,x-1);
            if(s.count(x+1))
                un(x,x+1);
        }
    int mer=c[m]+c[m+1]-cnt;
    int sumi=accumulate(c+l,c+m+1,0ll);
    int sumj=accumulate(c+m+1,c+r+1,0ll);
    int ans=(r-m)*sumi+(m-l+1)*sumj-(r-m)*(m-l+1)*mer;
    int prev_x=-1;
    int prev_k=-1;
//    cout<<"("<<l<<".."<<m<<") .. ("<<m+1<<".."<<r<<") -> "<<ans<<" -> ";
    for(auto pr:mp)
    {
        int x=pr.first;
        int k=pr.second;
        if(prev_x!=-1&&prev_x+1==x&&prev_k!=k)
        {
            int a1=a[x],a2=a[prev_x];
            if(a1>a2)
                swap(a1,a2);
            if(a1!=m||a2!=m+1)
                ans-=(a1-l+1)*(r-a2+1);
        }
        prev_x=x;
        prev_k=k;
    }
//    cout<<ans<<"\n";
    return ans+solve(l,m)+solve(m+1,r);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[a[i]].push_back(i);
    cout<<solve(1,n);
}