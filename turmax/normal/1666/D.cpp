#include <bits/stdc++.h>

using namespace std;
#define int long long
map <int,int> u;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s1,s2;cin>>s1>>s2;u.clear();for(auto h:s2) u[h]++;
        string ans;
        for(int i=s1.size()-1;i>=0;--i)
        {
            if(u[s1[i]])
            {
                ans.insert(ans.begin(),s1[i]);
                u[s1[i]]--;
            }
        }
        cout<<(ans==s2 ? "YES" : "NO")<<'\n';
    }
    return 0;
}