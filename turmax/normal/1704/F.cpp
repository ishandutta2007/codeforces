#include <bits/stdc++.h>

using namespace std;
#define int long long
bool used[10];
int nim[500005];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    nim[1]=0;nim[2]=1;
    for(int i=3;i<=500004;++i)
    {
        for(int j=0;j<10;++j) used[j]=false;
        used[nim[i-2]]=true;
        for(int j=1;j<min(i-2,500LL);++j)
        {
            used[nim[j]^nim[i-2-j]]=true;
        }
        bool ok=false;
        for(int j=0;j<10;++j)
        {
            if(!used[j])
            {
                nim[i]=j;ok=true;break;
            }
        }
    }
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;string s;cin>>s;
        vector<pair<char,int> > v;int cur=0;
        int sum1=0;int sum2=0;
        for(int i=0;i<n;++i)
        {
            if(i!=0 && s[i]!=s[i-1])
            {
                v.push_back({s[i-1],cur});cur=1;
            }
            else {++cur;}
        }
        v.push_back({s.back(),cur});
        for(int i=0;i<n;++i) if(s[i]=='R') ++sum1; else ++sum2;
        vector<pair<char,int> > u;
        char beg=s[0];cur=1;
        for(int i=1;i<n;++i)
        {
            if(s[i]!=s[i-1])
            {
                ++cur;
            }
            else
            {
                u.push_back({beg,cur});
                beg=s[i];cur=1;
            }
        }
        u.push_back({beg,cur});
        int h=0;
        for(auto [c,cnt]:u)
        {
            h^=nim[cnt];
        }
        if(h==0)
        {
            if(sum1>sum2) cout<<"Alice"<<'\n';
            else cout<<"Bob"<<'\n';
        }
        else
        {
            if(sum1>=sum2) cout<<"Alice"<<'\n';
            else cout<<"Bob"<<'\n';
        }
    }
    return 0;
}