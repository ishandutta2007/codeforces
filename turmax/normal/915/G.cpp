#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
vector <pair<int,int> > del1(vector <int> v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector <pair<int,int> > h;
    if(v.empty()) {h.push_back({1,1});return h;}
    int sz=(1<<v.size());
    for(int mask=0;mask<sz;++mask)
    {
        int o1=1;
        int o2=1;
        for(int i=0;i<v.size();++i)
        {
            if(mask & (1<<i))
            {
                o1*=v[i];
                o2*=(-1);
            }
        }
        h.push_back({o2,o1});
    }
    return h;
}
const int maxn=2e6+5;
int po1[maxn+1];
bool used[maxn];
int mi[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    used[0]=true;used[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(!used[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                if(!used[j])
                {
                    mi[j]=i;
                    if(j!=i)
                    {
                        used[j]=true;
                    }
                }
            }
        }
    }
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=maxn;++i)
    {
        po1[i]=po(i,n);
        //cout<<i<<" i "<<po1[i]<<" po1[i] "<<endl;
    }
    int answ[k+1];
    int ans=1;
    answ[1]=1;
    for(int i=2;i<=k;++i)
    {
        vector <int> v;
        int x=i;
        while(x!=1)
        {
            v.push_back(mi[x]);
            x/=mi[x];
        }
        int o=v.size();
        vector <pair<int,int> > h;
        if(!o)
        {
            h.push_back({1,1});
        }
        else
        {
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
            o=v.size();
            int sz=(1<<o);
            for(int mask=0;mask<sz;++mask)
            {
                int o1=1;int o2=1;
                for(int i=0;i<o;++i)
                {
                    if(mask & (1<<i))
                    {
                        o1*=v[i];
                        o2*=(-1);
                    }
                }
                h.push_back({o2,o1});
            }
        }
        for(int j=0;j<h.size();++j)
        {
            //cout<<v[j].first<<" v[j].first "<<v[j].second<<" v[j].second "<<i<<" i "<<endl;
            ans-=po1[(i/h[j].second)-1]*h[j].first;
            ans+=po1[(i/h[j].second)]*h[j].first;
            //cout<<ans<<" ans "<<endl;
        }
        ans%=p;
        ans+=p;
        ans%=p;
        answ[i]=ans;
    }
    int sum=0;
    for(int i=1;i<=k;++i)
    {
        sum+=(answ[i]^i);
        sum%=p;
    }
    cout<<sum;
    return 0;
}