#include <bits/stdc++.h>

using namespace std;
#define int long long
const int cnt=2e18;
const int maxn=53;
int fact[maxn];
int dp[maxn];
int mul(int x,int y)
{
    if(x>(cnt/y)) return cnt;
    else return (x*y);
}
int pl(int x,int y)
{
    return min(x+y,cnt);
}
bool ch(vector <int> v)
{
    int n=v.size();
    bool used[n]={0};
    vector <int> g;
    for(int i=0;i<n;++i)
    {
        if(used[i]) continue;
        vector <int> l={i};
        int curr=i;
        while(true)
        {
            curr=v[curr];
            used[curr]=true;
            if(curr==i) break;
            l.push_back(curr);
        }
        if(*max_element(l.begin(),l.end())!=v[i]) return false;
        if(*min_element(l.begin(),l.end())!=(v[i]-l.size()+1)) return false;
    }
    return true;
}
vector <int> strgo(int n,int k)
{
    cout<<" strgo "<<n<<' '<<k<<endl;
    vector <int> v;
    for(int i=0;i<n;++i) v.push_back(i);
    vector <vector <int> > t;
    if(ch(v)) t.push_back(v);
    while(next_permutation(v.begin(),v.end()))
    {
        if(ch(v)) t.push_back(v);
    }
    cout<<t.size()<<" t.size() "<<endl;
    return t[k];
}
vector <int> go2(int n,int k)
{
    assert(fact[n-2]>k);
    if(n==2) return {2,1};
    if(n==3) return {3,1,2};
    /*if(n==4)
    {
        if(k==0)
        {
            return {4,1,2,3};
        }
        else
        {
            return {4,3,1,2};
        }
    }*/
    bool used[n+1]={0};
    int curr=(n-3);
    vector <int> v(n);
    v[0]=n;
    used[n]=true;int ban[n+1]={0};int pr[n+1]={0};
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<n;++j)
        {
            if(!used[j] && j!=(i+1))
            {
                int o=i;
                while(pr[o]!=0) o=pr[o];
                if(j==(o+1)) continue;
                if(i==(n-1) || k<fact[curr])
                {
                    used[j]=true;
                    v[i]=j;
                    pr[j-1]=i;
                    curr--;
                    break;
                }
                else
                {
                    k-=fact[curr];
                }
            }
        }
    }
    return v;
}
vector <int> go(int n,int k)
{
    assert(dp[n]>k);
    if(n==0) return {};
    if(n==1)
    {
        return {1};
    }
    if(n==2)
    {
        if(k==0) return {1,2};
        else return {2,1};
    }
    if(dp[n-1]>k)
    {
        vector <int> v=go(n-1,k);
        for(auto &h:v) ++h;
        v.insert(v.begin(),1);
        return v;
    }
    k-=dp[n-1];
    for(int j=(n-2);j>=0;j--)
    {
        int o=mul(dp[j],fact[n-j-2]);
        if(o<=k)
        {
            k-=o;
            continue;
        }
        else
        {
            //cout<<n<<" n "<<j<<" j "<<endl;
            vector <int> z=go(j,k%dp[j]);
            for(auto &h:z)
            {
                h+=(n-j);
            }
            vector <int> v=go2(n-j,k/dp[j]);
            //for(auto h:v) cout<<h<<" h "<<endl;
            for(auto h:z) v.push_back(h);
            return v;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<maxn;++i) fact[i]=mul(fact[i-1],i);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<maxn;++i)
    {
        dp[i]=dp[i-1];
        for(int j=(i-2);j>=0;j--)
        {
            dp[i]=pl(dp[i],mul(dp[j],fact[i-j-2]));
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(dp[n]<k)
        {
            cout<<(-1)<<endl;
            continue;
        }
        vector <int> v=go(n,k-1);
        /*vector <int> v2=strgo(n,k-1);
        for(auto &h:v2) ++h;
        if(v!=v2)
        {
            cout<<n<<' '<<k<<endl;
            for(auto h:v) cout<<h<<" h1 "<<endl;
            for(auto h:v2) cout<<h<<" h "<<endl;
            return 0;
        }*/
        for(auto h:v) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}