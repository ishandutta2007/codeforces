#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e6+5;
bool is[maxn];
bool used[maxn];
int deq[maxn];
int z[maxn];
bool is1[maxn];
bool use1[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int cou(int x,int y)
{
    int ans=0;
    while(x%y==0)
    {
        x/=y;
        ++ans;
    }
    return ans;
}
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1) return v;
    if(!used[x])
    {
        v.push_back(x);
        return v;
    }
    v=rasl(x/z[x]);
    v.push_back(z[x]);
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    used[0]=true;used[1]=true;
    for(int i=0;i<maxn;++i)
    {
        if(!used[i])
        {
            for(int j=(2*i);j<maxn;j+=i)
            {
                used[j]=true;
                z[j]=i;
            }
        }
    }
    int ans=0;
    int n;
    cin>>n;
    set <int> u;
    map <int,int> m;
    vector <int> keys;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(m.count(x)) m[x]++;
        else
        {
            u.insert(x);
            keys.push_back(x);
            m[x]=1;
        }
    }
    vector <int> v;
    sort(keys.begin(),keys.end());reverse(keys.begin(),keys.end());
    for(auto h:keys)
    {
        bool f=true;
        if(use1[h]) f=false;
        else for(int i=(2*h);i<maxn;i+=h) if(is1[i]) f=false;
        use1[h]=true;
        if(m[h]==1)
        {
            ans*=m[h];
            if(f){
            v.push_back(h);
            is1[h]=true;
            }
            else
            {
            v.push_back(h-1);
            is1[h-1]=true;
            }
        }
        else
        {
            if(m[h]>=3) ans=1;
            v.push_back(h);
            v.push_back(h-1);
            is1[h]=true;
            is1[h-1]=true;
        }
    }
    sort(v.begin(),v.end());int sz=v.size();v.erase(unique(v.begin(),v.end()),v.end());
    if(v.size()!=sz) ans=1;
    for(auto h:v) is[h]=true;
    for(int i=1;i<maxn;++i)
    {
        if(is[i])
        {
            for(int j=(2*i);j<maxn;j+=i)
            {
                if(is[j])
                {
                    ans=1;
                }
            }
        }
    }
    int res=1;
    for(int i=2;i<maxn;++i)
    {
        if(!used[i])
        {
            int o=0;
            pair <int,int> l={-1,-1};
            for(int j=i;j<maxn;j+=i)
            {
                if(is[j])
                {
                    l=max(l,{max(o,cou(j,i)),min(o,cou(j,i))});
                    o=max(o,cou(j,i));
                }
            }
            //if(o) {cout<<o<<" o "<<endl;cout<<i<<" i "<<endl;}
            deq[i]=l.second;
            res*=po(i,o);
            res%=p;
        }
    }
    for(auto h:v)
    {
        bool f=true;
        for(int p:rasl(h))
        {
            //cout<<h<<" h "<<endl;
            //cout<<p<<" p "<<endl;
            if(deq[p]<cou(h,p))
            {
                f=false;
            }
        }
        if(f) ans=1;
    }
    cout<<(res+ans)%p;
    return 0;
}