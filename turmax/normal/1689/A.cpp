#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m,k;cin>>n>>m>>k;
        string s1,s2;cin>>s1>>s2;
        string ans;int cur=0;int u=(-1);
        sort(s1.begin(),s1.end());sort(s2.begin(),s2.end());
        while(true)
        {
            if(s1.empty() || s2.empty()) break;
            if(s1[0]<s2[0] && (u!=0 || cur<k))
            {
                ans+=s1[0];s1.erase(s1.begin());
                if(u!=0) {u=0;cur=1;}
                else {++cur;}
            }
            else if(u!=1 || cur<k)
            {
                ans+=s2[0];s2.erase(s2.begin());
                if(u!=1) {u=1;cur=1;}
                else {++cur;}
            }
            else
            {
                ans+=s1[0];s1.erase(s1.begin());
                 if(u!=0) {u=0;cur=1;}
                else {++cur;}
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}