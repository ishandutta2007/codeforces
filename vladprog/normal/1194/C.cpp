#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s,t,p;
        cin>>s>>t>>p;
        int cnt[26]={};
        for(char c:p)
            cnt[c-'a']++;
        bool ok=false;
        for(int i=0,j=0;j<t.size();j++)
        {
            if(i<s.size()&&s[i]==t[j])
                i++;
            else if(!cnt[t[j]-'a'])
            {
                ok=false;
                break;
            }
            else
                cnt[t[j]-'a']--;
            if(i==s.size())
                ok=true;
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
}