#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector <char> v;
        set <char> u;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!u.count(s[i]))
            {
                v.push_back(s[i]);
            }
            u.insert(s[i]);
        }
        int cnt[26]={0};
        for(int i=0;i<s.size();++i) cnt[s[i]-'a']++;
        reverse(v.begin(),v.end());
        int l=0;
        for(int i=0;i<v.size();++i)
        {
            l+=cnt[v[i]-'a']/(i+1);
        }
        //cout<<l<<" l "<<endl;
        if(l>s.size())
        {
            cout<<(-1)<<endl;
            continue;
        }
        string s1;
        for(int i=0;i<l;++i) s1+=s[i];
        string h=s1;
        string ans=h;
        for(auto l:v)
        {
            //cout<<l<<" l "<<endl;
            string h1;
            for(auto h2:h)
            {
                if(h2!=l) h1.push_back(h2);
            }
            //cout<<h1<<" h1 "<<endl;
            ans+=h1;
            h=h1;
        }
        string v1;
        for(auto h:v) v1.push_back(h);
        if(ans==s) cout<<s1<<' '<<v1<<endl;
        else cout<<(-1)<<endl;
    }
    return 0;
}