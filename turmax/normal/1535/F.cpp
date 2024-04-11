#pragma GCC optimize("O3","Ofast")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
string s[maxn];
int has[maxn];
mt19937_64 rnd;
int arr1[26];
int arr[maxn][26];
int getrnd()
{
    return (abs((int) rnd()));
}
int gethas1(string s)
{
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        ans+=arr[i][s[i]-'a'];
    }
    return ans;
}
int f(string s1,string s2)
{
    assert(s1.size()==s2.size());
    int n=s1.size();
    int pref=0;
    int suf=(n-1);
    for(int i=0;i<n;++i)
    {
        if(s1[i]!=s2[i]) {pref=i;break;}
    }
    for(int i=(n-1);i>=0;--i)
    {
        if(s1[i]!=s2[i]) {suf=i;break;}
    }
    bool ok1=1,ok2=1;
    for(int i=pref;i<=(suf-1);++i)
    {
        ok1=(ok1 && s1[i+1]>=s1[i]);
        ok2=(ok2 && s2[i+1]>=s2[i]);
    }
    if(ok1 || ok2) return 1;
    else return 2;
}
set <int> okhas;
set <pair<int,int> > d;
int slv(vector <int> v)
{
    int sz=s[v[0]].size();
    okhas.clear();
    d.clear();
    if(sz>=50)
    {
         int ans=0;
         for(int i=0;i<v.size();++i)
         {
             for(int j=(i+1);j<v.size();++j)
             {
                 ans+=f(s[v[i]],s[v[j]]);
             }
         }
         return ans;
    }
    for(int i=0;i<v.size();++i) okhas.insert(gethas1(s[v[i]]));
    for(int i=0;i<v.size();++i)
    {
        string t=s[v[i]];
        int ha=gethas1(s[v[i]]);
        for(int i=0;i<t.size();++i)
        {
            string t1=t;
            for(int j=(i+2);j<=t.size();++j)
            {
                int curr=(j-1);
                while(curr>i && t1[curr]<t1[curr-1]) {swap(t1[curr-1],t1[curr]);curr--;}
                int o=gethas1(t1);
                if(okhas.count(o) && o!=ha)
                {
                    d.insert({min(ha,o),max(ha,o)});
                }
            }
        }
    }
    return v.size()*(v.size()-1)-d.size();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rnd.seed(time(NULL));
    for(int i=0;i<26;++i) arr1[i]=getrnd();
    for(int i=0;i<maxn;++i) for(int j=0;j<26;++j) arr[i][j]=getrnd();
    int n;
    cin>>n;
    int o[n][26];
    for(int i=0;i<n;++i) for(int j=0;j<26;++j) o[i][j]=0;
    map <int,vector <int> > u;
    vector <int> keys;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        has[i]=0;
        for(auto h:s[i])
        {
            o[i][h-'a']++;
            has[i]+=arr1[h-'a'];
        }
        if(!u.count(has[i]))
        {
            keys.push_back(has[i]);
            u[has[i]]={i};
        }
        else
        {
            u[has[i]].push_back(i);
        }
    }
    int ans=(n*(n-1)/2)*1337;
    for(auto h:keys)
    {
        int cnt=u[h].size();
        ans-=(cnt*(cnt-1)/2)*1337;
        ans+=slv(u[h]);
    }
    cout<<ans;
    return 0;
}