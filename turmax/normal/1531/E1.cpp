#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
bool ok;
int curr;
vector <int> go(int l,int r)
{
    if(!ok) return {};
    if((r-l)==1) return {l};
    vector <int> v1=go(l,(l+r)/2);vector <int> v2=go((l+r)/2,r);
    if(!ok) return {};
    vector <int> v;
    if(curr>=s.size()) {ok=0;return {};}
    int l1=0,l2=0;
    while(true)
    {
        if(l1==v1.size())
        {
            while(l2!=v2.size())
            {
                v.push_back(v2[l2]);++l2;
            }
            break;
        }
        if(l2==v2.size())
        {
            while(l1!=v1.size())
            {
                v.push_back(v1[l1]);++l1;
            }
            break;
        }
        if(curr>=s.size())
        {
            ok=0;
            return {};
        }
        if(s[curr]=='0')
        {
            v.push_back(v1[l1]);++l1;
        }
        if(s[curr]=='1')
        {
            v.push_back(v2[l2]);++l2;
        }
        ++curr;
    }
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    for(int n=1;n<1500;++n)
    {
        ok=1;
        curr=0;
        vector <int> ans=go(0,n);
        if(!ans.empty() && ok && curr==s.size())
        {
            int res[n];
            for(int i=0;i<ans.size();++i) res[ans[i]]=(i+1);
            cout<<n<<endl;
            for(int i=0;i<n;++i) cout<<res[i]<<' ';
            return 0;
        }
    }
    return 0;
}