#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

set<int> g[26];
bool was[26];

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
        for(int i=0;i<26;i++)
            g[i].clear(),
            was[i]=false;
        for(int i=0;i+1<s.size();i++)
        {
            int a=s[i]-'a';
            int b=s[i+1]-'a';
            g[a].insert(b);
            g[b].insert(a);
        }
        bool ok=true;
        for(int i=0;i<26;i++)
            if(g[i].size()>2)
                ok=false;
        if(!ok)
        {
            cout<<"NO\n";
            continue;
        }
        string ans;
        for(int i=0;i<26;i++)
            if(!was[i]&&g[i].size()<=1)
            {
                int j=i,p=-1;
                while(true)
                {
                    ans+='a'+j;
                    was[j]=true;
                    bool found=false;
                    for(int k:g[j])
                        if(k!=p)
                        {
                            found=true;
                            p=j;
                            j=k;
                            break;
                        }
                    if(!found)
                        break;
                }
            }
        if(ans.size()==26)
            cout<<"YES\n"<<ans<<"\n";
        else
            cout<<"NO\n";
    }
}