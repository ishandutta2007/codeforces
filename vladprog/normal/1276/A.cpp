#include<bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> ans;
        for(int i=0;i<s.size();i++)
            if(i+5-1<s.size()&&s.substr(i,5)=="twone")
                ans.push_back(i+3),
                s[i+2]='_';
            else if(i+3-1<s.size()&&(s.substr(i,3)=="one"||s.substr(i,3)=="two"))
                ans.push_back(i+2),
                s[i+1]='_';
        cout<<ans.size()<<"\n";
        for(int i:ans)
            cout<<i<<" ";
        cout<<"\n";
    }
}