#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    int u=n;
    cin>>s;
    n=s.size();
    int ans=0;
    vector <pair<int,int> > a;
    for(int i=0;i<100;++i)
    {
        n=s.size();
        a.clear();
        for(int i=0;i<n;++i)
        {
            a.push_back({s[i]-'a',i});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        for(int j=0;j<n;++j)
        {
            int x=a[j].second;
            if((x>=1 && (s[x]-s[x-1])==1) || (x<(n-1) && (s[x]-s[x+1])==1))
            {
                s.erase(s.begin()+x);
                break;
            }
        }
    }
    cout<<u-s.size()<<endl;
    return 0;
}