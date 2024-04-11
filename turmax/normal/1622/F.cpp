#include <bits/stdc++.h>

using namespace std;
#define int long long
mt19937_64 rnd;
const int maxn=1e6+5;
int has[maxn];bool used[maxn];int has2[maxn];bool ok[maxn];int n;
void init()
{
    used[0]=true;used[1]=true;has[0]=0;
    for(int i=2;i<maxn;++i)
    {
        if(used[i]) {has2[i]=has2[i-1]^has[i];continue;}
        has[i]=rnd();
        has2[i]=has2[i-1]^has[i];
        for(int j=2*i;j<maxn;j+=i)
        {
            used[j]=true;
            int o=0;int j1=j;while(j1%i==0) {j1/=i;++o;}
            if(o & 1) has[j]^=has[i];
        }
    }
}
void getans()
{
    ok[1]=true;
    int sum=0;for(int i=1;i<=n;++i) sum+=ok[i];
    cout<<sum<<endl;
    for(int i=1;i<=n;++i) if(ok[i]) cout<<i<<' ';
    exit(0);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rnd.seed(228);
    int val=0;
    init();
    cin>>n;
    for(int i=1;i<=n;++i) ok[i]=true;
    for(int i=1;i<=n;++i) {val^=has2[i];}
    if(val==0)
    {
        cerr<<" ok0 "<<endl;
        getans();
    }
    for(int i=1;i<=n;++i)
    {
        if(has2[i]==val)
        {
            ok[i]=false;
            cerr<<" ok1 "<<endl;
            getans();
        }
    }
    vector <pair<int,int> > u;
    u.push_back({(1LL<<62)-1,-1});
    for(int i=1;i<=n;++i)
    {
        u.push_back({has2[i],i});
    }
    sort(u.begin(),u.end());
    for(int i=0;i<u.size()-1;++i)
    {
        pair <int,int> t=u[i];
        int val2=t.first^val;
        pair <int,int> o=(*lower_bound(u.begin(),u.end(),make_pair(val2,(int) -2)));
        if(o.first==val2)
        {
            ok[t.second]=false;ok[o.second]=false;
            cerr<<" ok2 "<<endl;
            getans();
        }
    }
    if(n%4==0)
    {
        ok[n/2]=false;
    }
    else if(n%4==2)
    {
        ok[2]=false;
        ok[n/2]=false;
    }
    else if(n%4==1)
    {
        ok[n]=false;
        ok[n/2]=false;
    }
    else if(n%4==3)
    {
        ok[n]=false;
        ok[2]=false;
        ok[n/2]=false;
    }
    getans();
    return 0;
}