#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+3;
bool is[21];
int x;
unordered_map <string,int> z;
int32_t o[50000000];
bool o1[50000000];
int curr=0;
bool check(string s)
{
    vector <int> v(s.size());
    int sum=0;
    for(int i=0;i<s.size();++i)
    {
        v[i]=s[i]-'0';
        sum+=v[i];
    }
    if(sum!=x) return true;
    //if(is[sum]) return false;
    int n=s.size();
    int pr[n+1];pr[0]=0;
    set <int> d;
    d.insert(0);
    for(int i=0;i<=n;++i)
    {
        pr[i+1]=pr[i]+v[i];
        d.insert(pr[i+1]);
    }
    for(int u=1;u<x;++u)
    {
        if(x%u==0)
        {
            for(int i=0;i<=n;++i)
            {
                if(d.count(pr[i]+u))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool rcheck(string s)
{
    vector <int> v(s.size());
    int n=s.size();
    for(int i=0;i<n;++i) v[i]=s[i]-'0';
    int sum=0;
    bool ans=true;
    for(int i=(n-1);i>=0;i--)
    {
    sum+=v[i];
    if(sum==x)
    {
        string u;
        for(int j=i;j<n;++j)
        {
            u+=s[j];
        }
        return check(u);
    }
    }
    return ans;
}
string s;
int dp(int i,string h)
{
    int has;
    if(!z.count(h)) {z[h]=curr;has=49000*i+curr;++curr;}
    else has=49000*i+z[h];
    if(i==s.size()) return 0;
    if(o1[has]) return o[has];
    char u=s[i];
    string h1=(h+u);
    int ans=dp(i+1,h)+1;
    int sum=0;
    string t1;
    for(int i=h1.size()-1;i>=0;i--)
    {
        sum+=(h1[i]-'0');
        if(sum>x)
        {
            break;
        }
        else
        {
            t1+=h1[i];
        }
    }
    reverse(t1.begin(),t1.end());
    if(rcheck(t1))
    {
        if(x%(t1[t1.size()-1]-'0')==0)
        {
            t1="";
        }
        ans=min(ans,dp(i+1,t1));
    }
    o1[has]=true;
    o[has]=ans;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //is[11]=true;is[13]=true;is[17]=true;is[19]=true;
    cin>>s;
    cin>>x;
    string h;
    cout<<dp(0,h);
    return 0;
}